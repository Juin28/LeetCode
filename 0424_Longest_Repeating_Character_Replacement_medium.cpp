class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int max_cnt = 0;
        int l = 0;
        int r = 0;
        int cnt [26] = {0};
        int result = 0;

        while (r < n)
        {
            ++cnt[s[r] - 'A'];
            max_cnt = max(max_cnt, cnt[s[r] - 'A']);

            int len = r - l + 1;
            if (len - max_cnt > k)
            {
                --cnt[s[l] - 'A'];
                ++l;
            }
            max_cnt = max(max_cnt, cnt[s[l] - 'A']);
            result = max(result, r - l + 1);
            ++r;
        }

        return result;
    }
};
