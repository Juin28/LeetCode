class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
                x.push(c);
            else
            {
                if (x.empty())
                    return false;
                char open = x.top();
                char close = c;
                char ans_close = '\0';
                switch (open)
                {
                    case '(':
                        ans_close = ')';
                        break;
                    
                    case '[':
                        ans_close = ']';
                        break;

                    case '{':
                        ans_close = '}';
                        break;
                    default:
                        break;
                }

                if (close != ans_close)
                    return false;
                
                x.pop();
            }
        }

        if (x.empty())
            return true;
        return false;
        
    }
};