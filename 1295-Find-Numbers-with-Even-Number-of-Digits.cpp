class Solution {
public:
    int findNumbers(vector<int>& v) {
        int count = 0 ;
        for(int i =0 ; i < v.size() ; i++ ){
            string a = to_string(v[i]);
            if(a.size() %2 == 0){
                count++;
            }
        }
        return count;
    }
};
