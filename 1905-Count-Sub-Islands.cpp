class Solution {
public:
    bool dfs(int i , int j , vector<vector<int>>& v1, vector<vector<int>>& v2, vector<vector<int>>& vis){
        if ( i < 0 || i >= v1.size() || j < 0 || j >= v1[0].size() || vis[i][j] == 1 || v2[i][j] == 0){
            return true;
        }
        vis[i][j] = 1;
        bool check = true;
        if(v1[i][j] == 0){
            check = false;
        }
        bool a = dfs(i + 1, j, v1, v2, vis);
        bool b = dfs(i - 1, j, v1, v2, vis);
        bool c = dfs(i, j + 1, v1, v2, vis);
        bool d = dfs(i, j - 1, v1, v2, vis);
        return check && a && b && c && d;
    }
    int countSubIslands(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int n = v1.size();
        int m = v1[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0; j < m ;j++){
                if(v2[i][j] == 1 && vis[i][j] == 0){
                    if(dfs(i, j, v1, v2, vis)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
