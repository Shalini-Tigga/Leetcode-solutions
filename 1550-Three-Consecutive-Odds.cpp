class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& v) {
        for(int i = v.size() - 1 ; i >= 2 ; i--){
            if(v[i] % 2 != 0 && v[i-1] % 2 != 0 && v[i-2] % 2 != 0 ){
                return true;
            }
        }
        return false;
    }
};
