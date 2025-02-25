class Solution {
public:
    //top down dp 
    int func(int n , vector<int>& dp){
        if( n <= 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int one_step = func(n-1, dp);
        int two_step = func(n-2, dp);
        return dp[n] = one_step + two_step;
    }
    int climbStairs(int n) {
        vector<int> dp(n+2 , -1);
        int val = func(n+1, dp);
        return dp[n+1];
    }
};
