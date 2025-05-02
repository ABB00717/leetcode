#include <string>
#include <vector>

class Solution {
public:
  int countSeniors(std::vector<std::string> &details) {
    int result = 0;

    for (std::string information : details) {
      int age = std::stoi(information.substr(11, 2));

      if (age > 60) {
        result++;
      }
    }

    return result;
  }
};
