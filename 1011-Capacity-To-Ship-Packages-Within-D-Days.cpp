class Solution {
public:
    bool func (int m ,vector<int>& v, int k ){
        int count = 1, curr = 0 ; 
        for(int i : v){
            if(curr + i > m){
                count++;
                curr = i;
                if(count > k){
                    return false;
                }
            }else{
                curr += i;
            }
        }
        return (count <= k);
    }
    int shipWithinDays(vector<int>& v, int k) {
        int h = 0, l = *max_element(v.begin(), v.end());
        for(int i : v){
            h += i;
        }
        while(l<h){
            int m = l + (h-l)/2;
            if(func(m,v,k)){
                h = m;
            }else{
                l = m+1;
            }
        }
        return l;
    
    }
};
