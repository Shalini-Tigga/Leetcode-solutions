class Solution {
public:
    bool dfs ( int i , int j , int counter , vector<vector<char>>& v, string x, vector<vector<int>>& vis){
        if( i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || vis[i][j] == 1 || v[i][j] != x[counter]){
            return false;
        }
        vis[i][j] = 1;
        counter++;
        if(counter == x.size()){
            return true;
        }
        bool a = dfs(i + 1, j, counter, v, x, vis);
        bool b = dfs(i - 1, j, counter, v, x, vis);
        bool c =  dfs(i, j + 1, counter, v, x, vis);
        bool d = dfs(i, j - 1, counter, v, x, vis);
        vis[i][j] = 0 ; 
        return a || b || c|| d ;
    }
    bool exist(vector<vector<char>>& v, string x) {
        int n = v.size(); 
        int m = v[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && v[i][j] == x[0]){
                    if( dfs(i , j , 0 , v , x , vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};



