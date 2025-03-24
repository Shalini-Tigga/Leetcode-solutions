class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> v(n, vector<int>(n)); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) { 
                v[j][n - i - 1] = arr[i][j];  
            }
        }
        arr = v;  
    }
};
