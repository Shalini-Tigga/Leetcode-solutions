class Solution {
public:
    //DFS
    void solve(int x, int y, vector<vector<char>>& v,vector<vector<int>>& vis){
        int n = v.size();
        int m = v[0].size();
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        vis[x][y] = 1;
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 && newy>=0 && newx<n && newy<m && vis[newx][newy] == 0 && v[newx][newy] == '1'){
                solve(newx,newy,v,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0;
        vector<vector<int>> vis(n , vector<int> (m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(v[i][j] == '1' && vis[i][j] == 0){
                    ans++;
                    solve(i,j, v,vis);
                }
            }
        }
        return ans;
    }
};
