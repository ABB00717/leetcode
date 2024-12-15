#include <queue>
#include <vector>

class Solution {
private:
  struct Class {
    double ratio;
    int pass;
    int total;

    Class(int pass, int total)
        : ratio((double)pass / total), pass(pass), total(total) {}

    void addStudent() {
      pass++;
      total++;
      ratio = (double)pass/total;
    }
    
    bool operator<(const Class &other) const { 
      double thisGain = (double)(pass+1)/(total+1) - (double)(pass)/(total);
      double otherGain = (double)(other.pass+1)/(other.total+1) - (double)(other.pass)/(other.total);
      return thisGain < otherGain; 
    }
  };

public:
  double maxAverageRatio(std::vector<std::vector<int>> &classes,
                         int extraStudents) {
    std::priority_queue<Class> classesPriority;
    for (auto &classUnit : classes)
      classesPriority.emplace(classUnit[0], classUnit[1]);
    
    while (extraStudents > 0) {
      Class classUnit = classesPriority.top();
      classesPriority.pop();
      classUnit.addStudent();
      classesPriority.emplace(classUnit);
      extraStudents--;
    }

    double result = 0;
    while (!classesPriority.empty()) {
      result += classesPriority.top().ratio;
      classesPriority.pop();
    }

    return result / classes.size();
  }
};
