#include "LegoRobot.h"
#include "utility.h"

const auto pi = 3.14159265358979323846;
const auto ticks_to_mm_conversion = 0.349;
const auto robot_width_mm = 150.0;

Pose2D filter_step(Pose2D, MotorTickRecord, double, double);

int main() {

  namespace plt = matplotlibcpp;

  LegoRobot l;
  l.read("../../UnitA/robot4_motors.txt");
  auto motor_tick_diffs = l.getMotorTicks();

  vector<double> x_coors;
  vector<double> y_coors;

  Pose2D pose = {0.0, 0.0, 0.0};

  for (const auto &tick_record : motor_tick_diffs) {
    pose =
        filter_step(pose, tick_record, ticks_to_mm_conversion, robot_width_mm);
    x_coors.push_back(get<0>(pose));
    y_coors.push_back(get<1>(pose));
  }

  plt::plot(x_coors, y_coors, "bo");
  plt::show();
}

Pose2D filter_step(Pose2D old_pose, MotorTickRecord tick, double ticks_to_mm,
                   double robot_width) {

  auto [left_tick, right_tick] = tick;
  auto [old_x, old_y, old_heading] = old_pose;
  auto robot_mid = robot_width / 2;

  // If robot is going straight keep last heading and just update x,y
  if (left_tick == right_tick) {
    double new_heading = old_heading;

    double new_x = old_x + (left_tick * ticks_to_mm) * cos(new_heading);
    double new_y = old_y + (left_tick * ticks_to_mm) * sin(new_heading);

    return {new_x, new_y, new_heading};
  }

  // If turning, calculate turn_rad, and alpha to update x,y, heading
  else {
    double left_wheel_dist_mm = (left_tick * ticks_to_mm);
    double right_wheel_dist_mm = (right_tick * ticks_to_mm);

    double alpha = (right_wheel_dist_mm - left_wheel_dist_mm) / robot_width;

    double turn_rad = left_wheel_dist_mm / alpha;

    double center_x = old_x - (turn_rad + robot_mid) * sin(old_heading);
    double center_y = old_y - (turn_rad + robot_mid) * -1 * cos(old_heading);

    double new_heading = fmod((old_heading + alpha), (2 * pi));
    double new_x = center_x + (turn_rad + robot_mid) * (sin(new_heading));
    double new_y = center_y + (turn_rad + robot_mid) * (-1 * cos(new_heading));

    return {new_x, new_y, new_heading};
  }
}
