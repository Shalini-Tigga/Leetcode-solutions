class Solution {
public:
    int countConsistentStrings(string s, vector<string>& v) {
        int count = 0; 
        for (string& word : v) {
            bool consistent = true;
            for (char c : word) {
                if (s.find(c) == string::npos) {  // If any character is not in 's'
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }
        return count;
    }
};
