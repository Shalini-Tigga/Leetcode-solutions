class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> st;
        for(char a : s){
            if( a == '('){
                st.push(')');
            }else if(!st.empty() &&st.top() == a ){
                st.pop();
            }else{
                count++;
            }
            
        }
        return st.size() +count;
    }
};
