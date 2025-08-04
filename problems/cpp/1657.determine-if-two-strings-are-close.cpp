#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int n = word1.size();
        for (int i = 0; i < n; i++) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0) != (freq2[i] == 0))
                return false;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

int main() {
    Solution solution;
    solution.closeStrings("uau", "ssx");
}
