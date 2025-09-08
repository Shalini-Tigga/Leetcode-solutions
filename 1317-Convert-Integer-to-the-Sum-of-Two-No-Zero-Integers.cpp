class Solution {
public:
    bool if_zero( int n ){
        string a = to_string(n);
        for(char b : a){
            if( b == '0'){
                return true;
            }
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1 ; i < n ; i++){
            if(if_zero(i)){
                continue;
            }
            int check = n - i;
            if(if_zero(check)){
                continue;
            }
            if(check <= n && check >= 1){
                return {i , check};
            }
        }
        return {0,0};
    }
};
