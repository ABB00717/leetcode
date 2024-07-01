class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string str : strs) {
            string orderedStr = str;
            std::sort(orderedStr.begin(), orderedStr.end());
            anagrams[orderedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};