class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int p = 0;
        while (s[p] != '\0')
        {
            int cur_val = 0;
            int next_val = 0;
            switch (s[p])
            {
                case 'I':
                    cur_val = 1;
                    break;
                case 'V':
                    cur_val = 5;
                    break;
                case 'X':
                    cur_val = 10;
                    break;
                case 'L':
                    cur_val = 50;
                    break;
                case 'C':
                    cur_val = 100;
                    break;
                case 'D':
                    cur_val = 500;
                    break;
                case 'M':
                    cur_val = 1000;
                    break;
                default:
                    break;
            }

            if (s[p+1] != '\0')
            {
                switch (s[p+1])
                {
                    case 'I':
                        next_val = 1;
                        break;
                    case 'V':
                        next_val = 5;
                        break;
                    case 'X':
                        next_val = 10;
                        break;
                    case 'L':
                        next_val = 50;
                        break;
                    case 'C':
                        next_val = 100;
                        break;
                    case 'D':
                        next_val = 500;
                        break;
                    case 'M':
                        next_val = 1000;
                        break;
                    default:
                        next_val = 0;
                        break;
                }
            }

            if (cur_val >= next_val)
                result += cur_val;
            else
                result -= cur_val;
            p++;
        }
        return result;
    }
};