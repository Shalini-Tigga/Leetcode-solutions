class Solution {
public:
    string removeOuterParentheses(string s) {
        stack <int> st;
        string a = ""; 
        int count = 0;
        for(char i : s){
            st.push(i);
            if(i == '('){
                if(count > 0){
                    st.push(i);
                    a += i;
                }
                count++;
            }else{
                count--;
                if(count > 0){
                    st.push(i);
                    a += i;
                }
            }  
        }
        return a;
    }
};
