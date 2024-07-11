class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        int strsIndex = 0, strIndex = 0, char ch = strs[0][0];
        while (true) {
            if (strs[strsIndex][strIndex] != ch || strIndex == strs[strsIndex].length())
                return result;

            strsIndex++;
            if (strsIndex == strs.size()) {
                result += strs[strsIndex-1][strIndex];
                strsIndex = 0;
                strIndex++;
                ch = strs[strsIndex][strIndex];
            }
        }

        return result;
    }
};