class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char, int> m ;
        for(int i : s){
            m[i]++;
        }
        priority_queue<pair<int,char>> p;
        for(auto& it : m){
            p.push({it.second, it.first});
        }
        string a = "";
        while(!p.empty()){
            int k = p.top().first;
            while(k--){
                a += p.top().second;
            }
            p.pop();
        }
        return a;
    }
};
