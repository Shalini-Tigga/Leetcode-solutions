class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin() , v.end());
        set<vector<int>> s;
        for(int i = 0 ; i <v.size() ; i++){
            int j = i + 1, k = v.size() - 1;
            while( j < k){
                int sum = v[i] + v[j] + v[k];
                if( sum == 0){
                    s.insert({v[i],v[j], v[k]});
                    j++; 
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        vector<vector<int>> ans (s.begin(), s.end());
        return ans;
    }
};
