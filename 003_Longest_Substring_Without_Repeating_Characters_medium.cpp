class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        {
            return 0;
        }
        
        int ans_p1 = 0;
        int ans_p2 = 0;
        int track_p1 = 0;
        int track_p2 = 0;
        int idx[128] {-1};
        bool track[128] {false};

        for (int i = 0; i < s.length(); i++)
        {
            if (track[s[i]])
            {
                int temp = track_p1;
                track_p1 = idx[s[i]] + 1;
                track_p2 = i;
                for (int j = 0; j < (idx[s[i]] - temp); j++)
                {
                    track[s[j + temp]] = false;
                }
                for (int k = 0; k <= (idx[s[i]] - temp); k++)
                {
                    idx[s[k + temp]] = -1;
                }
                idx[s[i]] = i;
            }
            else
            {
                track[s[i]] = true;
                idx[s[i]] = i;
                track_p2 = i;
            }

            if ((track_p2 - track_p1) > (ans_p2 - ans_p1))
            {
                ans_p1 = track_p1;
                ans_p2 = track_p2;
            }
            
        }
        return ans_p2 - ans_p1 + 1;
    }
};
