class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;
        if (target < 0) {
            return -1; 
        }

        if (target == 0) {
            return n; 
        }

        int maxLength = -1;
        int currSum = 0, left = 0;

        for (int right = 0; right < n; right++) {
            currSum += nums[right];

            while (currSum > target) {
                currSum -= nums[left];
                left++;
            }

            if (currSum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        return maxLength == -1 ? -1 : n - maxLength;
    }
};
