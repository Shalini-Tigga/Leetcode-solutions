class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& v) {
        unordered_map<int, int> mp;
        int count = 0;

        for (auto& d : v) {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            count += mp[key];
            mp[key]++;
        }

        return count;
    }
};
