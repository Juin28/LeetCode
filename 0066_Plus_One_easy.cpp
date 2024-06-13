class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
        for (int i = last; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }

            else if (i == 0)
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
                return digits;
            }

            digits[i] = 0;
        }
        return digits;
    }
};