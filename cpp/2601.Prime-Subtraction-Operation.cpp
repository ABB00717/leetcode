#include <cmath>
#include <vector>

class Solution {
private:
  std::vector<int> primeTable;

  bool isPrime(int num) {
    for (int i = 3; i <= std::sqrt(num); i += 2) {
      if (num % i == 0) return false;
    }

    return true;
  }

  int findSuitablePrime(int a, int b) {
    if (a < b) return a;

    for (int i = 0; i < primeTable.size() && a - primeTable[i] > 0; i++) {
      if (a - primeTable[i] < b) return a - primeTable[i];
    }

    return -1;
  }
  
public:
  bool primeSubOperation(std::vector<int> &nums) {
    primeTable.push_back(2);
    for (int i = 3; i <= 1000; i += 2) {
      if (isPrime(i)) primeTable.push_back(i);
    }

    for (int i = nums.size()-2; i >= 0; i--) {
      int newValue = findSuitablePrime(nums[i], nums[i+1]); 

      if (newValue == -1) return false;
      else nums[i] = newValue;
    }

    return true;
  }
};