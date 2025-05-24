class Solution {
public:
    vector<int> findWordsContaining(vector<string>& arr, char x) {
         vector<int> v;  
        for (int i = 0; i < arr.size(); i++) {  
            if (arr[i].find(x) != string::npos) {  
                v.push_back(i);  
            }
        }
        return v;
    }
};
