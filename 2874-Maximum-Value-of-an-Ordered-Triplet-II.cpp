class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long maxValue = 0;
        int max_i = nums[0];  
        vector<int> maxSuffix(n, 0);
        maxSuffix[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; --k) {
            maxSuffix[k] = max(maxSuffix[k + 1], nums[k]);
        }
        for (int j = 1; j < n - 1; ++j) {
            max_i = max(max_i, nums[j - 1]); 
            long long tripletValue = (1LL * (max_i - nums[j]) * maxSuffix[j + 1]);
            maxValue = max(maxValue, tripletValue);
        }

        return maxValue;
    }
};
