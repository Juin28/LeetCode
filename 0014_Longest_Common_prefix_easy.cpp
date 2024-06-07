class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool same = true;
        string ans = "";
        char a = '\0';
        int idx = 0;
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();

        while((first[idx] == last[idx]) && (first[idx] != '\0') && (last[idx] != '\0'))
        {
            ans.push_back(first[idx]);
            idx++;
        }

        return ans;
    }
};