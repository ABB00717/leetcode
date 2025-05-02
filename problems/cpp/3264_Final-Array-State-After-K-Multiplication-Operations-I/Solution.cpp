#include <queue>
#include <vector>

class Solution {
private:
  struct Num {
    int val;
    int index;

    Num(int val, int index) : val(val), index(index) {}

    bool operator<(const Num &other) const {
      return this->val > other.val ||
             (this->val == other.val && this->index > other.index);
    }
  };

public:
  std::vector<int>& getFinalState(std::vector<int> &nums, int k,
                                 int multiplier) {
    std::priority_queue<Num> numsPriority;

    for (int i = 0; i < nums.size(); i++) {
      numsPriority.push(Num(nums[i], i));
    }

    while (k-- > 0) {
      auto num = numsPriority.top();
      num.val *= multiplier;
      numsPriority.pop();
      numsPriority.push(num);
      nums[num.index] = num.val;
    }

    return nums;
  }
};
