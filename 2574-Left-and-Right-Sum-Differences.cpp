class Solution {
public:
    vector<int> leftRightDifference(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, 0);
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = leftSum;
            leftSum += v[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += v[i];
        }

        return ans;
    }
};
