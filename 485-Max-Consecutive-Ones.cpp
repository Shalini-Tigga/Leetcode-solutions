class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0 , maxs = 0;
        for(int i = 0 ; i <nums.size() ;i++){
            if(nums[i] == 1){
                curr++;
                maxs = max(curr,maxs);
            }else{
                curr = 0;
            }
        }
        return maxs;
    }
};
