class Solution {
public:
    bool cyclecheck(int i , vector<int>& vis , vector<vector<int>>& adj){
        vis[i] = 1;
        for(auto it : adj[i]){
            if(vis[it] == 0){
                if(cyclecheck(it,vis,adj)){
                    return true;
                }
            }else if( vis[it] ==1 ){
                return true;
            }
        }
        vis[i] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        for(auto it : v){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis (n,0);
        for(int i =0 ; i < n ; i++){
            if(vis[i] == 0){
                if(cyclecheck(i , vis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
