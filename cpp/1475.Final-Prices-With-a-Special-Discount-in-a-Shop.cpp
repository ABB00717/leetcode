#include <stack>
#include <vector>
class Solution {
/*
遍歷 prices，在這過程中持續把每個 price 的 index 丟進 stack，假設當前的 price 小於 stack 上的 price，
則透過 index 更改那個 price 值，並且持續這麼做直到不符合條件，之後才繼續遍歷 price。
*/
public:
  std::vector<int> finalPrices(std::vector<int> &prices) {
    std::stack<int> stack;

    for (int i = 0; i < prices.size(); i++) {
      while (!stack.empty() && prices[stack.top()] >= prices[i]) {
        prices[stack.top()] -= prices[i];
        stack.pop();
      }
      stack.push(i);
    }

    return prices;
  }
};