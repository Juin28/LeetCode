class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            columnNumber--;
            int idx = columnNumber % 26;
            ans.push_back(idx + 'A');
            columnNumber /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};