class Solution {
public:
    void helper (int n, int openN, int closeN, string current, vector<string>& ans) {
        if (openN == closeN && openN == n)
        {
            ans.push_back(current);
            return;
        }
        
        if (openN < n)
        {
            helper(n, openN + 1, closeN, current + "(", ans);
        }

        if (closeN < openN)
        {
            helper(n, openN, closeN + 1, current + ")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, 0, "", ans);
        return ans;
    }
};
