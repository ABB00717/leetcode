class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];

        for (auto str : strs) {
            string section = "";
            int index = 0;
            while (index < result.length() && section.length() != result.length() && str[index] == result[index]) {
                section.push_back(str[index]);
                index++;
            }

            result = section;
        }

        return result;
    }
};