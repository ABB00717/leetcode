#include <stack>
#include <string>
class Solution {
public:
  bool canBeValid(std::string s, std::string locked) {
    int n = s.size();
    if (n % 2)
      return false;

    for (int i = 0; i < n; i++) {
      if (locked[i] == '0') {
        s[i] = '-';
      }
    }

    std::stack<int> left, unlocked;
    for (int i = 0; i < n; i++) {
      if (s[i] == '-') {
        unlocked.push(i);
      } else if (s[i] == ')') {
        s[i] = 'x';
        if (!left.empty()) {
          s[left.top()] = 'x';
          left.pop();
        } else if (!unlocked.empty()) {
          s[unlocked.top()] = 'x';
          unlocked.pop();
        } else {
          return false;
        }
      } else if (s[i] == '(') {
        left.push(i);
      }
    }

    std::stack<int> right;
    unlocked = std::stack<int>();
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'x')
        continue;

      if (s[i] == '-') {
        unlocked.push(i);
      } else if (s[i] == ')') {
        right.push(i);
      } else if (s[i] == '(') {
        if (!right.empty()) {
          s[right.top()] = 'x';
          right.pop();
        } else if (!unlocked.empty()) {
          s[unlocked.top()] = 'x';
          unlocked.pop();
        } else {
          return false;
        }
      }
    }

    int unlockedCount = 0;
    for (char c : s) {
      if (c == '-')
        unlockedCount++;
    }

    return unlockedCount % 2 == 0;
  }
};
