// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1)
            return 1;

        unsigned int l = 1;
        unsigned int r = n;
        while (l < r) 
        {
            unsigned int m = (l + r) >> 1;
            if ((m == l) && !isBadVersion(l) && isBadVersion(r))
                return r;
            
            if (isBadVersion(m))
                r = m;
            else
                l = m;
        }
        return l;
    }
};