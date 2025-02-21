class Solution {
public:
    bool cyclecheck(int i , vector<int>& vis , vector<vector<int>>& adj,stack<int>& s){
        vis[i] = 1;
        for(auto it : adj[i]){
            if(vis[it] == 0){
                if(cyclecheck(it,vis,adj,s)){
                    return true;
                }
            }else if( vis[it] ==1 ){
                return true;
            }
        }
        vis[i] = 2;
        s.push(i);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& v) {
         vector<vector<int>> adj(n);
        for(auto it : v){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis (n,0);
        stack<int> s;
        for(int i =0 ; i < n ; i++){
            if(vis[i] == 0){
                if(cyclecheck(i , vis, adj,s)){
                    return {};
                }
            }
        }
        vector<int> ans(s.size());
        int i = 0;
        while(!s.empty()){
            ans[i] = s.top();
            s.pop();
            i++;
        }
        return ans;
    }
};
