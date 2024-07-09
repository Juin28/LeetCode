class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> check;
        int cnt = 0;
        for (const string& s: arr)
            ++check[s];

        for (const string& s: arr)
        {
            if (check[s] == 1)
            {
                ++cnt;
                if (cnt == k)
                    return s;
            }
        }

        return "";
    }
};