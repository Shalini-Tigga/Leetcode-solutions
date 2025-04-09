class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> greaterThanK;

        for (int num : nums) {
            if (num < k) return -1; 
            if (num > k) greaterThanK.insert(num);
        }

        return greaterThanK.size();
    }
};
