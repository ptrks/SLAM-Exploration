#include <iostream>
#include <cmath>
#include <string>
#include <tuple>
#include <vector>

using std::cos;
using std::fmod;
using std::get;
using std::sin;
using std::string;
using std::tuple;
using std::vector;
using std::stoi;

namespace utility {
namespace types {

using MotorTickRecord = tuple<int, int>;
using MotorTicks = vector<MotorTickRecord>;
using Pose2D = tuple<double, double, double>;

} // namespace types
} // namespace utility