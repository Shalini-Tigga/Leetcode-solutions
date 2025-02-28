class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        vector<int> res;
        unordered_map<int,int> map;
        for(int i  : v){
            map[i]++;
        }
        for(auto& pair : map){
            if(pair.second > v.size()/3){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};
