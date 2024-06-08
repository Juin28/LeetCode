class Solution {
public:
    string intToRoman(int num) {
        switch (num)
        {
            case 1:
                return "I";
                break;

            case 5:
                return "V";
                break;

            case 10:
                return "X";
                break;

            case 50:
                return "L";
                break;

            case 100:
                return "C";
                break;

            case 500:
                return "D";
                break;

            case 1000:
                return "M";
                break;
            
            default:
                break;
        }
        string ans = "";
        int remainder = num;

        if (remainder >= 1000) {
            int d = remainder/1000;
            int c = remainder/1000;
            for (int i = 0; i < d; i++)
            {
                ans.push_back('M');
            }
            remainder = remainder - c * 1000;
        }

        if (remainder >= 100) {
            int d = remainder/100;
            int c = remainder/100;
            if ( d == 4 || d == 9)
            {
                ans.push_back('C');
                (d == 4) ? ans.push_back('D') : ans.push_back('M');
            }
            else 
            {
                if (d >= 5)
                {
                    ans.push_back('D');
                    d -= 5;
                }
                while (d != 0)
                {
                    ans.push_back('C');
                    d--;
                }
            }
            remainder = remainder - c * 100;
        }

        if (remainder >= 10) {
            int d = remainder/10;
            int c = remainder/10;
            if ( d == 4 || d == 9)
            {
                ans.push_back('X');
                (d == 4) ? ans.push_back('L') : ans.push_back('C');
            }
            else 
            {
                if (d >= 5)
                {
                    ans.push_back('L');
                    d -= 5;
                }
                while (d != 0)
                {
                    ans.push_back('X');
                    d--;
                }
            }
            remainder = remainder - c * 10;
        }

        if (remainder >= 1) {
            int d = remainder;
            if ( d == 4 || d == 9)
            {
                ans.push_back('I');
                (d == 4) ? ans.push_back('V') : ans.push_back('X');
            }
            else 
            {
                if (d >= 5)
                {
                    ans.push_back('V');
                    d -= 5;
                }
                while (d != 0)
                {
                    cout << "d = " << d << endl;
                    ans.push_back('I');
                    d--;
                }
            }
        }

        return ans;
    }
};
