class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length() - 1;
        int ans = 0;

        if (len == 0)
            return (s[0] != ' ') ? 1 : 0;

        for (int i = len; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                while (i >= 0 && s[i] != ' ')
                {    
                    ans++;
                    i--;
                }
                break;
            }
        }
        return ans;
    }
};
