class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        if (k == 1)
            return n;
        
        vector<int> val (n);
        iota(val.begin(), val.end(), 1);
        int sum = 1;
        
        for (int i = 1; i < k; i++)
        {
            for(int j = 1; j < n; j++)
            {
                val[j] = (val[j] + val[j-1]) % 1000000007;
            }
        }
        
        return val[n-1];
    }
};