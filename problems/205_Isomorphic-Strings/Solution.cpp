class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, char> dictS, dictT;
        for (int i = 0; i < s.length(); i++) {
            if (dictS.find(s[i]) == dictS.end())
                dictS[s[i]] = t[i];
            else if (dictS[s[i]] != t[i])
                return false;

            if (dictT.find(t[i]) == dictT.end())
                dictT[t[i]] = s[i];
            else if (dictT[t[i]] != s[i])
                return false;
        } 

        return true;
    }
};
