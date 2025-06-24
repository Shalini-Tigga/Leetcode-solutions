class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& v, int x, int k) {
        int n = v.size();
        set<int> resSet;

        for (int i = 0; i < n; ++i) {
            if (v[i] == x) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j) {
                    resSet.insert(j);
                }
            }
        }

        return vector<int>(resSet.begin(), resSet.end());
    }
};
