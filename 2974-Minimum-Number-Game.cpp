class Solution {
public:
    vector<int> numberGame(vector<int>& v) {
        vector<int> res(v.size());
        priority_queue<int> q;
        for(int i : v){
            q.push(i);
        }
        int it = 0;
        for(int i = 0 ; i < v.size() ; i += 2 ){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            res[it] = b;
            it++;
            res[it] = a;
            it++;
        }
        reverse(res.begin() , res.end());
        return res;
    }
};
