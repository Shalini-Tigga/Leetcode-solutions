class Solution {
public:
    void helper(int i , vector<int>& arr , vector<vector<int>>& res, vector<int>& v){
        res.push_back(v);
        for(int j = i ; j < arr.size() ; j++){
            if( j > i && arr[j] == arr[j-1]){
                continue;
            }
            v.push_back(arr[j]);
            helper(j +1, arr, res, v);
            v.erase(v.end() -1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> v;
        helper(0, arr,res,v);
        return res;
    }
};
