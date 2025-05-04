class Solution {
public:
    bool dfs(int i, int d,vector<bool>& vis , vector<vector<int>>& v){
        if(i == d){
            return true;
        }
        vis[i] = true;
        for(int j : v[i]){
            if(!vis[j]){
                if(dfs(j, d, vis, v)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& v, int s, int d) {
        vector<vector<int>> adj(n);
        for(auto& i : v){
            int u = i[0] , w = i[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        vector<bool> vis (n , false);
        return dfs(s , d, vis, adj );
    }
};
