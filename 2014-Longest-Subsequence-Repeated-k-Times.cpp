class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q{ {""} };
        unordered_set<string> valid{""};
        string ans;
        while (q.size()) {
            auto x = q.front();
            q.pop();
            for (char c = 'a'; c <= 'z'; ++c) {
                auto y = x + c;
                auto suffix = y.substr(1);
                if (valid.count(suffix) == 0) continue; // suffix must be also valid.
                int matched = 0, i = 0, j = 0;
                for (; i < s.size() && matched < k; ++i) {
                    if (s[i] == y[j]) ++j;
                    if (j == y.size()) j = 0, ++matched;
                }
                if (matched == k) {
                    ans = y;
                    q.push(y);
                    valid.insert(y);
                }
            }
        }
        return ans;
    }
