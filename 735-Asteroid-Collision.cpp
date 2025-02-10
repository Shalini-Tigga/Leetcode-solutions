class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> st;
        vector<int> res;
        for(int i : v){
            if(i > 0){
                st.push(i);
            }else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(i) ){
                    st.pop();
                }
                if(!st.empty() && st.top() > 0 && st.top() == abs(i)){
                    st.pop();
                }else if(!st.empty() && st.top() > 0 && st.top() > abs(i)){
                    continue;
                }else{
                    st.push(i);
                }
            }
        }
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }
            reverse(res.begin() , res.end());
            return res;
    }
};
