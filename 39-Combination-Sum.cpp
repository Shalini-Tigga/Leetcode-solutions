class Solution {
public:
    void helper(int i , vector<int>& arr , vector<int>& v ,vector<vector<int>>& res, int k,int sum){
    if( i == arr.size()){
        if( sum == k){
            res.push_back(v);
        }
        return;
    }
    if(sum + arr[i] <= k){
        v.push_back(arr[i]);
        sum += arr[i];
        helper(i , arr, v,res, k,sum );
        v.erase(v.end() -1);
        sum -= arr[i];
    }
    helper(i +1, arr, v,res, k,sum);
    
}
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>> res;
        vector<int> v; 
        helper(0 , arr, v, res, k,0);
        return res;
    }
};
