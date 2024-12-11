class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x;
        for (int i = 0 ;i<nums.size();i++){
            if(i != nums[i]){
                return i;
                x = 1;
            }
        }
        return x;
    }
};
