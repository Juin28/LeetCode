class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            string s2 = to_string(s.back() - 'a' + 1);
            num.insert(0, s2);
            s.pop_back();
        }

        string tmp = num;
        unsigned long digit = 0;
        for (int i = 0; i < k; ++i)
        {
            digit = 0;
            while (!tmp.empty())
            {
                digit += tmp.back() - '0';
                tmp.pop_back();
            }
            tmp = to_string(digit);
        }

        return digit;
    }
};
