class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        for(int i = m.size() -1 ; i >= 0; i--){
            if(m[i][m[i].size()-1] >= target){
                for(int j = 0 ; j < m[i].size() ; j++){
                    if(m[i][j] == target ){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
