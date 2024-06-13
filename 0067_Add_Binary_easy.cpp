class Solution {
public:
    string addBinary(string a, string b) {
        int ap = a.length() - 1;
        int bp = b.length() - 1;
        int carryIn = 0;
        string ans = "";

        while (ap >= 0 || bp >= 0 || carryIn != 0)
        {
            if (ap >= 0)
                carryIn += a[ap--] - '0';
            if (bp >= 0)
                carryIn += b[bp--] - '0';
            ans.push_back(static_cast<char> (carryIn % 2 + '0'));
            carryIn /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }
};