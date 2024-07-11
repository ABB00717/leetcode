class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;

        for (auto ch : t) {
            if (s[0] == ch)
                s.erase(s.begin());

            if (s.empty())
                return true;
        }

        return false;
    }
};