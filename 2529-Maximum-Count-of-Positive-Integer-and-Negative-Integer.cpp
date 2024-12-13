class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p=0;
        int  n = 0;
        for (int i = 0;i<nums.size();i++){
            if(nums[i]>0){
                p = p +1;
            }else if(nums[i]<0){
                n= n +1;
            }else{
                continue;
            }
        }
        if(n>p){
            return n;
        }else{
            return p ;
        }
        
    }
};
