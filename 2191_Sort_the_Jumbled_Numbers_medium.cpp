class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> old_and_new(n);
        vector<int> sorted(n, 0);

        for (int i = 0; i < n; ++i) 
        {
            int original = nums[i];
            int result = 0;

            if (original == 0)
                result = mapping[0];

            else
            {
                int multiplier = 1;

                while (original > 0) 
                {
                    int digit = original % 10;
                    result += mapping[digit] * multiplier;
                    multiplier *= 10;
                    original /= 10;
                }
            }

            old_and_new[i].first = result;
            old_and_new[i].second = nums[i];
        }

        sort(old_and_new.begin(), old_and_new.end(),
             [&](pair<int, int>& a, pair<int, int>& b) {
                 return a.first < b.first;
             });

        for (int i = 0; i < n; ++i) 
        {
            sorted[i] = old_and_new[i].second;
        }

        return sorted;
    }
};