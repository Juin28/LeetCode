class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycle = 2*n - 2;
        if (k < n)
            return k;
        
        else if (k <= cycle)
            return cycle - k;

        int iter = k / cycle;
        k -= iter * cycle;
        return (k < n) ? k : cycle - k;
    }
};