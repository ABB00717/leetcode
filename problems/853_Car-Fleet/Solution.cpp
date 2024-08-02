#include <algorithm>
#include <vector>

class Solution {
public:
  int carFleet(int target, std::vector<int> position, std::vector<int> speed) {
    struct PositionSpeed {
      int position;
      double arriveTime;
    };

    std::vector<PositionSpeed> positionSpeed;
    int result = 0;

    for (int i = 0; i < position.size(); i++) {
      positionSpeed.push_back(
          {position[i], (double(target - position[i]) / speed[i])});
    }

    std::sort(positionSpeed.begin(), positionSpeed.end(),
              [](const PositionSpeed &a, const PositionSpeed &b) {
                return a.position > b.position;
              });

    double currentTime = 0;
    for (int i = 0; i < positionSpeed.size(); i++) {
      if (positionSpeed[i].arriveTime > currentTime) {
        currentTime = positionSpeed[i].arriveTime;
        result++;
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  int target = 17;
  std::vector<int> position = {8, 12, 16, 11, 7};
  std::vector<int> speed = {6, 9, 10, 9, 7};

  Solution solution;
  int result = solution.carFleet(target, position, speed);

  return 0;
}
