class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue <int> pq;
        for(int i=0; i<nums.size();i++){
            pq.push(nums[i]);
        }
        int product=0;
        product = pq.top()-1;
        pq.pop();
        product = product * (pq.top()-1);
        return product;
    }
};
