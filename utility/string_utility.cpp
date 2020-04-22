#include "string_utility.h"
#include <sstream>

namespace utility {

vector<string> string_split(const string &str, const char delim) {
  vector<string> result;
  std::stringstream ss(str);
  string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

} // namespace utility