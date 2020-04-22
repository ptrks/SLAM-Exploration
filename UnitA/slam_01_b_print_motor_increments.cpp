#include "LegoRobot.h"
#include "utility.h"

int main() {

  LegoRobot l;
  l.read("../../UnitA/robot4_motors.txt");
  auto motor_tick_diffs = l.getMotorTicks();

  for (const auto& [left, right] : motor_tick_diffs) {
    std::cout << "(" << left << "," << right << ")" << std::endl;
  }
}