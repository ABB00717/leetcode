#include <algorithm>
#include <stack>

class MinStack {
private:
  std::stack<int> stack;
  std::stack<int> minStack;

public:
  MinStack() {}

  void push(int val) {
    stack.push(val);
    int minVal = std::min(val, (minStack.empty() ? val : minStack.top()));
    minStack.push(minVal);
  }

  void pop() {
    if (stack.empty())
      return;

    stack.pop();
    minStack.pop();
  }

  int top() { return stack.top(); }

  int getMin() { return minStack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
