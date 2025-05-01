/*
 * @lc app=leetcode id=2071 lang=cpp
 *
 * [2071] Maximum Number of Tasks You Can Assign
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <set>
#include <vector>

class Solution {
public:
    int maxTaskAssign(std::vector<int>& tasks, std::vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        std::sort(tasks.begin(), tasks.end());
        std::sort(workers.begin(), workers.end());

        int l = 0, r = std::min(n, m), result = 0;;
        while (l <= r) {
            int m = (l + r) / 2;
            if (canAssign(tasks, workers, m, pills, strength)) {
                result = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }
private:
    bool canAssign(std::vector<int> tasks, std::vector<int>  workers, int mid, int pills, int strength) {
        if (mid == 0) return true;

        std::multiset<int> availWorkers(workers.begin(), workers.end());

        for (int i = mid - 1; i >= 0; i--) {
            int currentTask = tasks[i];
            auto it = availWorkers.lower_bound(currentTask);
            if (it != availWorkers.end()) {
                availWorkers.erase(it);
                continue;
            }

            if (pills > 0) {
                auto it = availWorkers.lower_bound(currentTask - strength);
                if (it != availWorkers.end()) {
                    availWorkers.erase(it);
                    pills--;
                    continue;
                } 
            }

            return false;
        }

        return true;
    }
};
// @lc code=end

