class Solution {
public:
    int search(vector<int>& v, int t) {
    int n = v.size();
    int l = 0, m = 0 , h=n-1;
    //while(h-l>1) also works but you need to check low and high element
    while(l <= h){ 
        m = l + (h-l)/2;
        if(v[m] == t){
            return m;
        }
        if(v[m]>t){
            h = m-1;
        }else {
            l = m+1;
        }
    }
    return -1;
    }
};
