class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> m;
        for(char a : s ){
            m[a]++;
        } 
        int maxs = INT_MIN;
        int mins = INT_MAX;
        for(pair a : m){
            if(a.second % 2 == 0 ){
                mins = min(mins , a.second);
            }else{
                maxs = max(maxs, a.second);
            }
        }
        return maxs - mins;
    }
};
