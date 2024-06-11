class Solution {
public:
    void recurse(vector<string>& ans, string digit, int depth, string temp, const vector<string> match)
    {
        if (depth >= digit.size())
        {
            ans.push_back(temp);
            return;
        }

        int idx = digit[depth] - '2';
        for(int i = 0; i < match[idx].size(); i++)
        {
            temp += match[idx][i];
            recurse(ans, digit, depth+1, temp, match);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> ans;

        if (len == 0)
            return ans;
        else if (len == 1)
        {
            switch(digits[0])
            {
                case 2:
                    return vector<string> {"a", "b", "c"};

                case 3:
                    return vector<string> {"d", "e", "f"};

                case 4:
                    return vector<string> {"g", "h", "i"};

                case 5:
                    return vector<string> {"j", "k", "l"};

                case 6:
                    return vector<string> {"m", "n", "o"};

                case 7:
                    return vector<string> {"p", "q", "r", "s"};

                case 8:
                    return vector<string> {"t", "u", "v"};

                case 9:
                    return vector<string> {"w", "x", "y", "z"};
            }
        }

        vector< string > match = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        }; 

        recurse(ans, digits, 0, "", match);
        return ans;
    }
};