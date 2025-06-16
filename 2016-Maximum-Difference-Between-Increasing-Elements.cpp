class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxs = INT_MIN;
        for(int i =0 ; i < nums.size() ; i++){
            for(int j = i ; j < nums.size() ;j++){
                if( nums[j]>nums[i]){
                    maxs = max(maxs , nums[j] - nums[i]);
                }
            }
        }
        return maxs == INT_MIN ? -1 : maxs;
    }
};
