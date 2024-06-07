class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 1)
            return s;

        string ans = "";
        vector<string> x (numRows);
        bool down = true;
        int idx = 0;

        for (int i = 0; i < s.length(); i++)
        {
            x[idx % numRows].push_back(s[i]);

            if (down)
                idx++;
            else
                idx--;
            
            if (idx == (numRows - 1))
                down = false;
            else if (idx == 0)
                down = true;
        }

        for (int j = 0; j < numRows; j++)
        {
            for (int k = 0; k < x[j].length(); k++)
            {
                ans.push_back(x[j][k]);
            }
            
        }
        return ans;
    }
};
