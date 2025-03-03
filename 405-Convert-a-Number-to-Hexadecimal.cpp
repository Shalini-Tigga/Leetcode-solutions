class Solution {
public:
    string toHex(int num) {
        stringstream ss;
    ss << hex << num; 
    string hexStr = ss.str();
    return hexStr ;
    }
};
