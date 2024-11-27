class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int a=0;
        int b = 0;
        for ( int i = 0 ; i<gain.size() ;i++){
            a = a + gain [i];
            b = max(b,a);
        }
        return b;
        }
}; 
