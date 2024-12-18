class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        if(s.size()<3){
            return count;
        }
        for (int i = 0 ; i < s.length() -2; i++){
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i+2] != s[i]){
                count++;
            }
        }
        return count;
        
    }
};
