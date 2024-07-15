class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;

        while (l < r)
        {

            char left = s[l];
            if (s[l] >= 'A' && s[l] <= 'Z')
                left = left - 'A' + 'a';
            char right = s[r];
            if (s[r] >= 'A' && s[r] <= 'Z')
                right = right - 'A' + 'a';

            if ((left < 'a' || left > 'z') && (left < '0' || left > '9'))
                ++l;
            else if ((right < 'a' || right > 'z') && (right < '0' || right > '9'))
                --r;
            else if (left != right)
                return false;
            else
            {
                ++l;
                --r;
            }
        }

        return true;
    }
};
