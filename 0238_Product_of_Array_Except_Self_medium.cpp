class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int no_zero_total = 1;
        int zero_cnt = 0;
        vector<int> product;
        for (const int& i : nums) {
            if (i == 0)
                ++zero_cnt;
            else
                no_zero_total *= i;
            total *= i;
        }

        if (zero_cnt > 1) {
            return vector<int> (nums.size(), 0);
        }

        for (const int& j : nums) {
            if (j == 0)
                product.push_back(no_zero_total);
            else
                product.push_back(total/j);
        }

        return product;
    }
};
