class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> importance(n, 0);

        for (auto road : roads) {
            importance[road[0]]++;
            importance[road[1]]++;
        }

        std::sort(importance.begin(), importance.end(), std::less<int>());

        long long result = 0;
        for (int i = 0; i < n; i++) {
            result += (i+1) * (long long)importance[i];
        }

        return result;
    }
};