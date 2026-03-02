/*
 * @lc app=leetcode id=2999 lang=cpp
 *
 * [2999] Count the Number of Powerful Integers
 */

// @lc code=start


#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int lenCount(long long n) {
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        return count;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, std::string s) {
        for (char c : s) {
            if ((c - '0') > limit) {
                return 0;
            }
        }

        int len_finish = lenCount(finish), len_start = lenCount(start);
        vector<long long> dp(len_finish + 1, 0);

        int i = 1, across = std::max(len_start, (int)s.size());
        for (i = 1; i < len_finish; i++) {
            long long s_ll = stoll(s.substr(0, i));

            if (i < across)
                dp[i] = 0;
            else if (i == across)
                dp[i] = 1;
            else
                dp[i] = limit + dp[i-1];
        }

        long long total = 0;
        i = len_finish - 1;
        string finish_str = to_string(finish);
        while (true) {
            int digit = finish_str[0] - '0';
            finish_str = finish_str.substr(1);

            if (dp[i] != 0)
                total += dp[i] * min(limit, digit);
            else {
                total += (digit > s[0] - '0') ? 1 : 0;
                break;
            }

            i--;
        }

        return total;
    }
};
// @lc code=end

