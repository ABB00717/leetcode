class Solution {
public:
    string encode(vector<string>& strs) {
        string result;

        for (auto str : strs) {
            result += to_string(str.length());
            result += "#";
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.length()) {
            int prevIndex = i;
            while (s[i] != '#') {
                i++;
            }

            int size = stoi(s.substr(prevIndex, i - prevIndex));
            string str = s.substr(i + 1, size);
            result.push_back(str);
            i = i + 1 + size;
        }

        return result;
    }
};