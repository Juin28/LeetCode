class Solution {
public:
    string countAndSay(int n, string str = "1") {
        if (n == 1)
            return str;

        string next_str = "";
        int cnt = 0;
        char num = '0';
        int l = str.length();
        for (int i = 0; i < l; ++i)
        {
            num = str[i];
            cnt = 1;
            ++i;
            while (i < l && str[i] == num)
            {    
                ++cnt;
                ++i;
            }
            --i;
            next_str.push_back(cnt+'0');
            next_str.push_back(num);
        }

        return countAndSay(n-1, next_str);
    }
};