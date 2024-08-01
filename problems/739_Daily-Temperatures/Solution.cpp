#include <stack>
#include <vector>

struct TemperatureStackData {
  int index;
  int temperature;
};

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    std::vector<int> result(temperatures.size(), 0);
    std::stack<TemperatureStackData> warmerTemperature;

    for (int i = 0; i < temperatures.size(); i++) {
      TemperatureStackData thisDay;
      thisDay.temperature = temperatures[i];
      thisDay.index = i;

      while (!warmerTemperature.empty() &&
             warmerTemperature.top().temperature < thisDay.temperature) {
        result[warmerTemperature.top().index] =
            i - warmerTemperature.top().index;
        warmerTemperature.pop();
      }

      warmerTemperature.push(thisDay);
    }

    return result;
  }
};
