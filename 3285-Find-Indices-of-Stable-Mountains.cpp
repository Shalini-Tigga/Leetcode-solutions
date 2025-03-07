class Solution {
public:
    vector<int> stableMountains(vector<int>& v, int k) {
        vector<int> res;
        for(int i = 1 ; i < v.size() ; i++){
            if( v[i-1] > k){
                res.push_back(i);
            }
        }
        return res;
    }
};
