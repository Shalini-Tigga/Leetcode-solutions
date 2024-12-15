class Solution {
public:
    string defangIPaddr(string address) {
        string k = "";
        for (int i = 0; i <address.length();i++){
            if( address[i] == '.' ){
                k = k + "[.]";
            }else{
            k = k + address[i];
            }
        }
        return k;
    }
};
