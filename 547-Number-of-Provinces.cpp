class Solution {
public:
    void dfs(int i , vector<int> adj[] , vector<int>& vis){
        vis[i] = 1;
        for(auto it : adj[i]){
            if( vis[it] == 0){
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> adj[n];
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < n;j++){
                if(v[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0 ; 
        vector<int> vis(n,0);
        for(int i = 0 ; i < n ;i++){
            if( vis[i] == 0){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
