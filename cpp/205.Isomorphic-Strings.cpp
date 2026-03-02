class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> s_to_t_map, t_to_s_map;

        for (size_t i = 0; i < s.length(); i++) {
            auto [it_s, inserted_s] = s_to_t_map.try_emplace(s[i], t[i]);
            auto [it_t, inserted_t] = t_to_s_map.try_emplace(t[i], s[i]);

            if (!inserted_s && it_s->second != t[i]) return false;
            if (!inserted_t && it_t->second != s[i]) return false;
        }

        return true;
    }
};
