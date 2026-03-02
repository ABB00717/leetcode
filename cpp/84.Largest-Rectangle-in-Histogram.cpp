#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    struct RectangleArea {
      int height;
      int index;
    };

    int result = 0;
    std::stack<RectangleArea> rectangles;
    for (int i = 0; i < heights.size(); i++) {
      int lastIndex = i;
      while (!rectangles.empty() && rectangles.top().height > heights[i]) {
        result = std::max(result, rectangles.top().height *
                                      (i - rectangles.top().index));
        lastIndex = rectangles.top().index;
        rectangles.pop();
      }

      rectangles.push({heights[i], lastIndex});
    }

    while (!rectangles.empty()) {
      result =
          std::max(result, rectangles.top().height *
                               ((int)heights.size() - rectangles.top().index));
      rectangles.pop();
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution solution;
  std::vector<int> heights = {2, 1, 5, 6, 2, 3};
  int result = solution.largestRectangleArea(heights);
  return 0;
}
