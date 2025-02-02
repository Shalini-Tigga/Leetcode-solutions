class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; 

        int l = 0, h = x, m = 0;
        int res;

        while (l <=h) {
            m = l + (h - l) / 2;
            if (1LL*m * m == x) {
                return m; 
            } else if (1LL*m * m < x) {
                res = m;
                l = m+1;
            } else {
                h = m -1;
            }
        }

        return res; 
    }
};
