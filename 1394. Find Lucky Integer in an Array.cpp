class Solution {
public:
    int findLucky(vector<int>& v) {
        unordered_map<int,int> m ;
        for(int a : v){
            m[a]++;
        }
        int maxs = INT_MIN;
        for(auto& pair : m){
            if(pair.first == pair.second){
                maxs = max( maxs , pair.second);
            }
        }
        return maxs == INT_MIN ? -1 : maxs;
    }
};
