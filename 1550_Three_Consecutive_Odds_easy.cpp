class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        int start = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) 
        {
            if (arr[i] % 2)
            {
                if (cnt == 0)
                    start = i;
                ++cnt;
                if (cnt == 3)
                    return true;
            }
            else
            {
                cnt = 0;
            }
        }
        return false;
    }
};