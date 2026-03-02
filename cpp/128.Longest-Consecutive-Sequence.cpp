class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        int result = 0;

        for (auto num : nums) {
            if (map.find(num) == map.end()) {
                map[num] = vector<int>{1, num, num};
                int left = num;
                int right = num;

                if (map.find(num-1) != map.end()) {
                    left = map[num-1][1];
                    map[num][0] += map[num-1][0];
                }

                if (map.find(num+1) != map.end()) {
                    right = map[num+1][2];
                    map[num][0] += map[num+1][0];
                }

                map[num][1] = left;
                map[num][2] = right;
                map[left][2] = right;
                map[right][2] = left;

                map[left][0] = map[right][0] = map[num][0];

                result = max(result, map[num][0]);
            }
        }

        return result;
    }
};