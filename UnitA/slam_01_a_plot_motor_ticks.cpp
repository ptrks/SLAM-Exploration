#include <fstream>
#include "utility.h"

int main() {

  namespace plt = matplotlibcpp;

  std::ifstream input_file("../../UnitA/robot4_motors.txt");

  if (!input_file.is_open()) {
    std::cout << "Unable to open file!";
    return 1;
  }

  vector<int> left_motor_ticks;
  vector<int> right_motor_ticks;

  string line;
  while (getline(input_file, line)) {
    auto raw_fields = utility::string_split(line, ' ');
    left_motor_ticks.push_back(stoi(raw_fields[2]));
    right_motor_ticks.push_back(stoi(raw_fields[6]));
  }

  plt::plot(left_motor_ticks);
  plt::plot(right_motor_ticks);
  plt::title("Absolute Motor Tick Data");
  plt::show();

  return 0;
}