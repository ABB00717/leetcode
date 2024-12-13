#include <queue>
#include <vector>

class Solution {
private:
  struct Data{
    int val;
    int index;

    bool operator<(const Data& other) const {
      // 實現最小堆
      return val > other.val || val == other.val && index > other.index;
    }
  };
public:
  long long findScore(std::vector<int> &nums) {
    // 如果是自訂資料結構的話，必須自行定義 operator
    std::priority_queue<Data> priNums;
    long long result = 0;

    for (int i = 0; i < nums.size(); i++) {
      priNums.push(Data{nums[i], i});
    }

    Data topVal = priNums.top();
    while (!priNums.empty()) {
      do {
        if (priNums.empty()) break;

        topVal = priNums.top();
        priNums.pop();
        // 如果被標記過就繼續
      } while (nums[topVal.index] == 0);
      
      if (topVal.val == 0) break;
      result += nums[topVal.index];
      // 把中左右都清零，當作標記
      nums[topVal.index] = 0;
      if (topVal.index != 0) nums[topVal.index-1] = 0;
      if (topVal.index != nums.size()-1) nums[topVal.index+1] = 0;
    }

    return result;
  }
};
