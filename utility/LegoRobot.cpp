#include <fstream>
#include <iostream>

#include "LegoRobot.h"
//#include "string_utility.h";

LegoRobot::LegoRobot() : motor_ticks_raw_(), motor_ticks_() {}

void LegoRobot::read(const string &file) {
  std::ifstream input(file);

  if (!input.is_open()) {
    exit(1);
  }

  string line;
  auto prev_values = tuple<int, int>();

  while (getline(input, line)) {

    auto message_type = line[0];
    auto raw_sensor_fields = utility::string_split(line, ' ');

    switch (message_type) {

    case 'M':
      auto lmotor_curr = std::stoi(raw_sensor_fields[2]);
      auto rmotor_curr = std::stoi(raw_sensor_fields[6]);

      // We store diff rather than absolute value, so first pass diffs on self
      if (motor_ticks_.size() == 0) {
        prev_values = tuple(lmotor_curr, rmotor_curr);
      }

      auto [lmotor_prev, rmotor_prev] = prev_values;
      motor_ticks_.push_back(
          tuple(lmotor_curr - lmotor_prev, rmotor_curr - rmotor_prev));
      prev_values = std::tuple(lmotor_curr, rmotor_curr);

      break;
    }
  }
}

vector<MotorTickRecord> LegoRobot::getMotorTicks() const {
  return motor_ticks_;
}
