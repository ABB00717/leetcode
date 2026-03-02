#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class TimeMap {
public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    timeMap[key].emplace_back(timestamp, value);
  }

  string get(string key, int timestamp) {
    if (timeMap.find(key) == timeMap.end()) {
      return "";
    }

    const auto &values = timeMap[key];
    auto it = upper_bound(
        values.begin(), values.end(), pair<int, string>(timestamp, ""),
        [](const auto &a, const auto &b) { return a.first < b.first; });

    if (it == values.begin()) {
      return "";
    }

    return prev(it)->second;
  }

private:
  unordered_map<string, vector<pair<int, string>>> timeMap;
};