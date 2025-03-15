class Solution {
public:
    int maximumGap(vector<int>& v) {
        if(v.size() < 2){
            return 0;
        }
        sort(v.begin() , v.end());
        int maxs = 0;
        for(int i = 1 ; i < v.size() ; i++){
            maxs = max(maxs , v[i] - v[i-1]);
        }
        return maxs;
    }
};
