class Solution {
public:
    int maxProduct(vector<int>& v) {
        int maxs = v[0];
    for(int i = 0 ; i <v.size() ; i++){
        int curr = 1;
        for(int j= i ; j< v.size() ;j++){
            curr *= v[j];
            maxs = max(maxs,curr );
        }
    }
    return maxs;
    }
};
