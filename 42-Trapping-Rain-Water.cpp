class Solution {
public:
    int trap(vector<int>& v) {
        int count = 0;
        vector<int> pre(v.size());
        pre[0] = v[0];
        for(int i = 1 ; i <v.size() ;i++){
            pre[i] = max(pre[i-1],v[i]);
        }
        vector<int> suff(v.size());
        suff[v.size() -1] = v[v.size() -1];
        for(int i = v.size() - 2; i >= 0; i--){
            suff[i] = max(suff[i + 1],v[i]); 
        }
        
        for(int i  = 0 ; i<v.size() ;i++){
            count += min(pre[i], suff[i] ) - v[i];
        }
        return count;
    }
};
