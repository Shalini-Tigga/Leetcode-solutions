class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char a : s){
            if(a == '(') st.push(')');
            else if ( a== '{') st.push('}');
            else if( a== '[') st.push(']');
            else{
                if(st.empty() || st.top() != a)  return false;
            
                st.pop();
            
            }
        }
        
        return st.empty();
    }
};
