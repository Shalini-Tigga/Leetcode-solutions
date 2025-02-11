class Solution {
public:
    void helper(int i , vector<int>& arr , vector<int>& v ,vector<vector<int>>& res, int k){
        if( k == 0){
            res.push_back(v);
            return;
        }
        for(int j = i ; j < arr.size() ; j++){
            if( j > i && arr[j] == arr[j-1]){
                continue;
            }
            if( arr[j] > k){
                break ;
            }
            v.push_back(arr[j]);
            helper(j +1, arr, v, res,k - arr[j]);
            v.erase(v.end() -1);
        }
    } 

    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> v;
        helper(0, arr,v,res,k);
        return res;
    }
};
