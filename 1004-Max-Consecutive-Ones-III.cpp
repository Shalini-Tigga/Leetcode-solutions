class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 , j  = 0 , ans =0,count = 0; 
        int check = 0;
        while(j<n){
            check += nums[j];
            if(nums[j] == 0){
                count++;
            }
            while(i<j && count >k){
                if(nums[i] == 0){
                    count--;
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        if(check == 0 && k == 0){
            return 0;
        }
        return ans;
    }
};
