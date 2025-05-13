class Solution {
    int MOD = 1e9+7;
    inline int modAdd(int a,int b){
        return ((a % MOD)+(b % MOD))% MOD;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        array<int,26> sfreq{};
        for(char c: s)
            sfreq[c-'a']++;
        
        for(int i=1;i<=t;++i){
            array<int,26> next_freq{};
            for(int j=0;j<26;++j){
                if(j<25)
                    next_freq[j+1] = sfreq[j];
                else{
                    next_freq[0] = sfreq[25];
                    next_freq[1] = modAdd(next_freq[1],sfreq[25]);
                }
            }
            sfreq = next_freq;
        }
        int string_size = 0;
        for(int i=0;i<26;++i)
            string_size = modAdd(string_size,sfreq[i]);
        
        return string_size;
    }
};
