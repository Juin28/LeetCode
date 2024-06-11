class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;

        else if (dividend == divisor) 
            return 1;

        unsigned int ans = 0;
        int sign = 1;

        if ( (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) )
            sign = -1;

        unsigned int abs_dividend = abs(dividend), abs_divisor = abs(divisor);

        while (abs_dividend >= abs_divisor) 
        {
            int multiply = 0;
            while ( abs_dividend > ( abs_divisor << (multiply + 1) ) ) 
                multiply++;
            abs_dividend -= abs_divisor << multiply;
            ans += 1 << multiply;
        }

        if (ans == (1 << 31) && sign == 1) return INT_MAX;

        return sign * ans;
    }
};
