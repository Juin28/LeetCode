class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        vector<string> ans;

        int p1 = 0, p2 = 0;
        while (p2 <= s1.length())
        {
            if (p2 == s1.length() || s1[p2] == ' ')
            {
                string tmp = s1.substr(p1, p2 - p1);
                mp1[tmp]++;
                ++p2;
                p1 = p2;
            }
            else
            {
                ++p2;
            }
        }
        p1 = 0, p2 = 0;
        while (p2 <= s2.length())
        {
            if (p2 == s2.length() || s2[p2] == ' ')
            {
                string tmp = s2.substr(p1, p2 - p1);
                mp2[tmp]++;
                ++p2;
                p1 = p2;
            }
            else
            {
                ++p2;
            }
        }

        for(auto it1 = mp1.begin(); it1 != mp1.end(); it1++) 
        {
            if (it1->second == 1 && mp2.find(it1->first) == mp2.end())
                ans.push_back(it1->first);
        }
        for(auto it2 = mp2.begin(); it2 != mp2.end(); it2++) 
        {
            if (it2->second == 1 && mp1.find(it2->first) == mp1.end())
                ans.push_back(it2->first);
        }

        return ans;
        
    }
};
