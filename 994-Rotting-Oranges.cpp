class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    cnt++;
                }  
                else if(grid[i][j]==1) cnt++;
            }
        }
        if(cnt==0) return 0;
        int time = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()){
            int sz = q.size();
            time++;
            int total=0;
            for(int i=0;i<sz;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(vis[x][y]==1){ total++; continue;}
                vis[x][y]=1;
                for(int k=0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && (vis[nx][ny]==0)  && (grid[nx][ny]==1)){
                        q.push({nx, ny});
                    }
                }
            }
            if(total==sz) time--;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((grid[i][j]==1) && (vis[i][j]==0)) return -1;
            }
        }
        return time-1;
    }
};
