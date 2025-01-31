class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0 ; i <n;i++){
            ans += arr[i];
        }
        if(k == n){
            return ans;
        }
        k = n-k;
        int mn = 1e9, sum = 0 , j = 0;
        for(int i = 0 ; i<n;i++){
            sum += arr[i];
            if(i-j+1 == k){
                mn = min(mn,sum);
                sum -= arr[j];
                j++;
            }
        }
        return ans-mn;
    }
};
