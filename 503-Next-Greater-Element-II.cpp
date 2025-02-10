class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack <int> s;
        vector<int> v(arr.size(),-1);
        for(int i = 2 * arr.size() - 1 ; i >= 0; i--){
            while( !s.empty() && s.top() <= arr[i% arr.size()]){
                s.pop();
            }
                if(i < arr.size() && !s.empty()){
                    v[i] = s.top();
                }
                s.push(arr[i%arr.size()]);
            
        }
        
        return v;
    }
};

