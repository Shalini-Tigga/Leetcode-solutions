class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack <int> s;
        vector<int> v(arr.size(),0);
        for(int i = arr.size() - 1 ; i >= 0; i--){
            while( !s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
            }
                if(!s.empty()){
                    v[i] = s.top() - i;
                }
                s.push(i);
            
        }
        return v;
    }
};
