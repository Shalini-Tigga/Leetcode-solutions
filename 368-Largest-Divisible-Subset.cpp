class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    vector<int> dp(n, 1);       
    vector<int> prev(n, -1);  
    int maxIndex = 0;    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    vector<int> result;
    int k = maxIndex;
    while (k >= 0) {
        result.push_back(nums[k]);
        k = prev[k];
    }

    reverse(result.begin(), result.end());
    return result;
    }
};
