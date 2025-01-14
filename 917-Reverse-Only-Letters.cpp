class Solution {
public:
    string reverseOnlyLetters(string s) {
        string a = "";
        for(int i = s.size()-1 ; i>=0;i--){
            if(isalpha(s[i])){
                a = a+ s[i];
            }
        }
        string b = "";
        int k =0;
        for(int i = 0;i<s.size();i++){
            if(isalpha(s[i])){
                b = b + a[k];
                k++;
            }else{
                b = b + s[i];
            }
        }
        return b;
    }
};
