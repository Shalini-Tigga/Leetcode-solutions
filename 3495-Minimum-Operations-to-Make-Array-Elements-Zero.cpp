class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = 0;

            long long power = 1;
            int k = 1;        
            while (power <= r) {
                long long start = power;
                long long end = min(r, power * 4 - 1);
                if (end >= l) {
                    long long overlapL = max(l, start);
                    long long overlapR = end;
                    if (overlapL <= overlapR) {
                        totalSteps += (overlapR - overlapL + 1) * 1LL * k;
                    }
                }
                power *= 4;
                k++;
            }

            result += (totalSteps + 1) / 2; 
        }

        return result;
    }
};
