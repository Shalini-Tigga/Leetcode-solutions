class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        vector<int> v;
        unordered_map < int , int > m;
        for(int i : arr){
            m[i]++;
        }
        priority_queue<pair<int, int>> q;
        for(auto& p : m ){
            q.push({p.second , p.first});
        }
        for(int i = 0 ; i < k ;i++){
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};
