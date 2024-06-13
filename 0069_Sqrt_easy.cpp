class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = 46341;

        while (l < r)
        {
            int m = (l+r)>>1;
            long sq_low = m * m;
            long sq_high = (long)(m+1) * (long)(m+1);
            if (x >= sq_low)
            {
                if (x < sq_high)
                    return m;
                l = m;
            }
            else 
                r = m;
        }

        return l;
    }
};