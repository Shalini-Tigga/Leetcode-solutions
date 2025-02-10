class Solution {
public:
    void helper(int start , vector<int>& arr , vector<vector<int>>& res, vector<int>& v){
        if( start == arr.size()){
            res.push_back(v);
            return;
        }
        v.push_back(arr[start]);
        helper(start + 1 , arr,res, v);
        v.erase(v.end() -1);
        helper(start + 1 , arr,res,v);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> res;
        vector<int> v;
        helper(0, arr,res,v);
        return res;
    }
};
