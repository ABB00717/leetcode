#include <cmath>
#include <queue>
#include <vector>
class Solution {
public:
  // 這其實沒啥好講的吧笑死
  long long pickGifts(std::vector<int> &gifts, int k) {
    std::priority_queue<int> giftsPriority;
    for (auto gift : gifts)
      giftsPriority.push(gift);

    for (int i = 0; i < k; i++) {
      int curGift = giftsPriority.top();
      giftsPriority.pop();
      int giftLeft = static_cast<int>(std::sqrt(curGift));
      giftsPriority.push(giftLeft);
    }

    long long result = 0;
    while (!giftsPriority.empty()) {
      result += giftsPriority.top();
      giftsPriority.pop();
    }

    return result;
  }
};
