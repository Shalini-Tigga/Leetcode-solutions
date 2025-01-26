class Solution {
public:
    bool func (int mid ,vector<int>& v, int k ){
        int count = 0; 
        for(int i =0 ; i < v.size() ; i++){
            count += ceil((double)(v[i]) / (double)(mid) );
        }
        return (count <= k);
    }
    int minEatingSpeed(vector<int>& v, int k) {
        // F F F T T T 
        int l = 1, h = *max_element(v.begin(), v.end());
        while( h - l >1){
            int m = l + (h-l)/2;
            if(func(m,v,k)){
                h = m;
            }else{
                l = m+1;
            }
        }
        return func(l,v,k) ? l :h;
    }
};
