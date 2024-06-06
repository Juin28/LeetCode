class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        
        string ans = "";
        int max_length = 0;

        for(int i = 0; i < s.length(); i++)
        {
            int lp = i, rp = i;
            while ( (lp >= 0) && (rp < s.length()) && (s[lp] == s[rp]) )
            {
                if (rp - lp + 1 > max_length)
                {
                    max_length = rp - lp + 1;
                    ans = s.substr(lp, rp - lp + 1);
                }
                lp--;
                rp++;
            }

            lp = i, rp = i + 1;
            while ( (lp >= 0) && (rp < s.length()) && (s[lp] == s[rp]) )
            {
                if (rp - lp + 1 > max_length)
                {
                    max_length = rp - lp + 1;
                    ans = s.substr(lp, rp - lp + 1);
                }
                lp--;
                rp++;
                }
        }
        if (ans.empty())
            ans.push_back(s[0]);
        return ans;
    }
};