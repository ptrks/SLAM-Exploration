#include "LegoRobot.h"
#include "utility.h"

int main() {

  namespace plt = matplotlibcpp;

  LegoRobot l;
  l.read("../../UnitA/robot4_motors.txt");
  auto motor_tick_diffs = l.getMotorTicks();

  vector<int> left;
  vector<int> right;

  for (const auto &[l, r] : motor_tick_diffs) {
    left.push_back(l);
    right.push_back(r);
  }

  plt::plot(left);
  plt::plot(right);
  plt::title("Motor Tick Differential Data");
  plt::show();

  return 0;
}