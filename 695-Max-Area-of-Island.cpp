class DSU {
    vector<int> parent; 
    int size; 
    public: 
    DSU(int n){
        parent.resize(n,-1);
        size = 1;
    }
    int find(int x){
        if(parent[x] < 0 ){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite ( int x , int y ){
        int parent_x = find(x);
        int parent_y = find(y);
        if( parent_x == parent_y){
            return;
        }
        if( parent[parent_x] <= parent[parent_y]){
            parent[parent_x] += parent[parent_y];
            parent[parent_y] = parent_x;
            size = max( size , abs(parent[parent_x])); // size of a tree is the abs(rank) of that value 
        }else{
            parent[parent_y] += parent[parent_x];
            parent[parent_x] = parent_y;
            size = max(size , abs(parent[parent_y]));
        }
    }
    int getmax(){
        return size;
    }
};
class Solution {
public:
    // dsu approach
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int n = v.size(); 
        int m = v[0].size(); 
        if( n == 1 && m == 1){
            return v[0][0];
        }
        DSU d1(n*m);
        bool check = false; 
        vector<int> d = {-1,0,1,0,-1};
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(v[i][j] == 1){
                    check = true;
                    int cell = i*m + j ; // cell no
                    for(int k = 1 ; k < 5 ; k++){
                        int x = i + d[k-1] , y = j + d[k]; //index of neighbours 
                        int celln = x*m + y; // cell id of neighbour 
                        if( x >= 0 && y >= 0 && x < n && y < m && v[x][y] == 1 ){
                            d1.unite(cell , celln );
                        }   
                    }
                }
            }
        }
        if( check ){
            return d1.getmax();
        }
            return 0;
        
    }
};
