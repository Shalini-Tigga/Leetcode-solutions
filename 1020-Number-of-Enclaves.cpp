class Solution {
public:
    void dfs(int i , int j ,vector<vector<int>>& v ){
        if( i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == 0){
            return;
        }
        v[i][j] = 0;
        dfs(i -1 , j , v );
        dfs(i + 1, j , v );
        dfs(i , j -1 , v );
        dfs(i , j +1 , v );
    }
    int numEnclaves(vector<vector<int>>& v) {
        int n = v.size() ; 
        int m = v[0].size(); 
        for(int i = 0 ; i < n ;i++){
            if(v[i][0] == 1){
                dfs(i , 0 , v);
            }
            if( v[i][m-1] == 1){
                dfs(i , m -1 , v);
            }
        }
        for(int i = 0 ; i < m ;i++){
            if(v[0][i] == 1){
                dfs(0 ,  i, v);
            }
            if( v[n-1][i] == 1){
                dfs(n-1 , i , v);
            }
        }
        int count = 0;
        for(int i = 0 ; i < v.size(); i++){
            for(int j = 0 ; j < v[0].size() ; j++){
                if(v[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};
