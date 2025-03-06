class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& v, int k) {
        int count = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if ( v[i] >= k){
                count++;
            }
        }
        return count;
    }
};
