class Solution {
int idx = 0;

public:
    string recurse(const string& s) {
        string ans = "";

        while (idx < s.length())
        {
            if (s[idx] == ')')
            {
                ++idx;
                reverse(ans.begin(), ans.end());
                return ans;
            }
            else if (s[idx] == '(')
            {
                ++idx;
                string next = recurse(s);
                ans += next;
            }
            else
            {
                ans += s[idx];
                ++idx;
            }
        }

        return ans;
    }

    string reverseParentheses(string s) {
        return recurse(s);
    }
};