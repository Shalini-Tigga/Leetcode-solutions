class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int ans = 0;
    int dp = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > threshold)
        dp = 0;
      else if (i > 0 && dp > 0 && isOddEven(nums[i - 1], nums[i]))
        ++dp;
      else
        dp = nums[i] % 2 == 0 ? 1 : 0;
      ans = max(ans, dp);
    }

    return ans;
  }

 private:
  bool isOddEven(int a, int b) {
    return a % 2 != b % 2; 
    }
};
