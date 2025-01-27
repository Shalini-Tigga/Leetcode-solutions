class Solution {
public:
    int findMin(vector<int>& v) {
        int l = 0 , m = 0 , h = v.size() -1;
        while(l < h){
            m = l + (h-l)/2;
            if(v[m] > v[h]){
                l = m+1;
            }else{
                h = m;
            }
        }
        return v[l];
    }
};
