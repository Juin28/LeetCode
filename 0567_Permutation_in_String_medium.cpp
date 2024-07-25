class Solution {
public:
    bool checkOccurence(int cnt_1[], int cnt_2[]) {
        for(int i = 0; i < 26; ++i)
        {
            if (cnt_1[i] != cnt_2[i])
                return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int s1_cnt [26] = {0}; 
        int s2_cnt [26] = {0}; 

        if (len2 < len1)    
            return false;

        for (char c: s1)
            ++s1_cnt[c - 'a'];

        int j = 0;
        for (; j < len1; ++j)
        {
            ++s2_cnt[s2[j] - 'a'];
        }

        for (int i = 0; i <= len2 - len1; ++i, ++j)
        {
            if (checkOccurence(s1_cnt, s2_cnt))
                return true;
            --s2_cnt[s2[i] - 'a'];
            if (j < len2)
                ++s2_cnt[s2[j] - 'a'];
        }
        
        return false;
        
    }
};
