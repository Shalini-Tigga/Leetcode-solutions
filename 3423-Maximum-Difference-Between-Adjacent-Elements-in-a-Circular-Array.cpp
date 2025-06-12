class Solution {
public:
    int maxAdjacentDistance(vector<int>& v) {
        int maxs = INT_MIN;
        for(int i = 0 ; i < v.size() -1 ; i++){
            maxs = max(abs(v[i] - v[i+1] ), maxs);
        }
        maxs = max(abs(v[v.size() - 1] - v[0]) , maxs);
        return maxs;
    }
};
