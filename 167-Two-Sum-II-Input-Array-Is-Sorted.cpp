class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int l = 0, r = v.size() - 1;
    while(l<r){
        if(v[l] + v[r] == t){
            return {l+1,r+1};
        }else if( v[l] + v[r] > t){
            r--;
        }else{
            l++;
        }
    }
    return {};
    }
};
