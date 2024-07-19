class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> num;
        for(const string& s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                int temp2 = num.top();
                num.pop();
                int temp1 = num.top();
                num.pop();
                int result = 0;

                if (s == "+")
                    num.push(temp1 + temp2);
                else if (s == "-")
                    num.push(temp1 - temp2);
                else if (s == "*")
                    num.push(temp1 * temp2);
                else
                    num.push(temp1 / temp2);
            }
            
            else
                num.push(stoi(s));
        }

        return num.top();
    }
};
