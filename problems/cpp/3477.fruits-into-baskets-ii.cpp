#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = fruits.size();
        for (int fruit : fruits) {
            int unset = 1;
            for (int &basket : baskets) {
                if (fruit <= basket) {
                    unset = 0;
                    basket = 0;
                    break;
                }
            }
            count += unset;
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> fruits = {9, 10, 11, 6, 1};
    vector<int> baskets = {1, 1, 100, 101, 102};
    solution.numOfUnplacedFruits(fruits, baskets);
}
