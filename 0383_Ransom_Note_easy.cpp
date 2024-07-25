class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomNote_cnt [26] = {0};
        int magazine_cnt [26] = {0};

        for (char c : ransomNote)
            ++ransomNote_cnt[c - 'a'];
        for (char c : magazine)
            ++magazine_cnt[c - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            if (ransomNote_cnt[i] > magazine_cnt[i])
                return false;
        }

        return true;
    }
};