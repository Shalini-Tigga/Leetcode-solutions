class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        int n = v.size();
        int x = lower_bound(v.begin(), v.end(), t) - v.begin();
        if (x == n || v[x] != t) {
            return {-1, -1}; 
        }
        int y = upper_bound ( v.begin(), v.end(), t)- v.begin() -1;
        return {x,y};
    }
};
