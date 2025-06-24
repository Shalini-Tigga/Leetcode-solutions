class Solution {
public:
    int dfs(int i , vector<vector<int>>& adj, vector<int>& vis){
        vis[i] =1 ;
        int count = 1 ;
        for(auto& it : adj[i]){
            if(vis[it] == 0){
                count += dfs(it, adj, vis);
            }
        }
        return count;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(int i = 0; i < r.size() ; i++){
            vis[r[i]] = 1; 
        }
        for(int i =0 ; i < edges.size() ; i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        return dfs(0 , adj, vis);
    }
};

