class Solution {
public:
    int myAtoi(string s) {
        if (s.empty())
            return 0;

        int p = 0;
        int sign = 1;
        while (static_cast<int> (s[p]) == 32)
            p++;

        if (static_cast<int> (s[p]) == 43)
            p++;
        else if (static_cast<int> (s[p]) == 45)
        {
            sign = -1;
            p++;
        }

        if (static_cast<int> (s[p]) < 48 || static_cast<int> (s[p]) > 57 )
            return 0;

        long long ans = 0;
        while (static_cast<int> (s[p]) >= 48 && static_cast<int> (s[p]) <= 57)
        {
            if ( sign*(ans*10 + static_cast<int> (s[p] - '0')) > INT_MAX)
                return INT_MAX;
            else if ( sign*(ans*10 + static_cast<int> (s[p] - '0')) < INT_MIN)
                return INT_MIN;

            ans = ans*10 + static_cast<int> (s[p] - '0');
            p++;
        }   

        ans *= sign;
        return ans;
    }
};