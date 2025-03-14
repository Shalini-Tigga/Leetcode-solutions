class Solution {
public:
int func(int i, vector<int>& nums, vector<int>& dp) {
    if (i == 0) return nums[0]; 
    if (i < 0) return 0; 

    if (dp[i] != -1) return dp[i]; 

    int pick = nums[i] + func(i - 2, nums, dp);  
    int not_pick = func(i - 1, nums, dp);  

    return dp[i] = max(pick, not_pick); 
}

int rob(vector<int>& nums) {
    // int n = nums.size();
    // vector<int> dp(n, -1);  
    // return func(n - 1, nums, dp); 

    //bottom up approach
    int n = nums.size();
    vector<int> dp(n, 0);  
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=dp[i-2];
        int not_pick=dp[i-1];
        dp[i]=max(pick,not_pick);

    }
    return dp[n-1];
}

};
