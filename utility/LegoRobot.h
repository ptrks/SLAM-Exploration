#pragma once

#include "utility.h"

using namespace utility;
using namespace utility::types;

class LegoRobot {
public:
  LegoRobot();
  void read(const string &file);
  vector<MotorTickRecord> getMotorTicks() const;

private:
  vector<int> reference_positions_;
  vector<int> scan_data_;
  vector<int> pole_indices_;
  vector<MotorTickRecord> motor_ticks_raw_;
  vector<MotorTickRecord> motor_ticks_;
  vector<int> filtered_positions_;
  vector<int> landmarks_;
  vector<int> detected_cylinders_;
  vector<int> last_ticks_;
};