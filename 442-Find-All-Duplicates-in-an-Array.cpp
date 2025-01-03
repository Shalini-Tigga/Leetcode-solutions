class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> m;
        for(int i =0;i<n;i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]] = m[nums[i]] + 1;
            }else{
                m[nums[i]] = 1;
            }
        }
        vector <int> v;
        for(auto curr : m){
            if(curr.second ==2){
                v.push_back(curr.first);

            }
        }
        return v;
    }
};
