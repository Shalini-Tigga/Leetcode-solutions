class Solution {
public:
    int scoreOfString(string s) {
        int count = 0; 
        count += abs((int)s[0]  - (int)s[1]);
        if(s.length() >2){
            for(int i = 1 ; i < s.length()-1  ; i++){
                count += abs((int)s[i] - (int)s[i+1]);
            }
        }
        return count;
    }
};
