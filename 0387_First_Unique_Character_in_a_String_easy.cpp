class Solution {
public:
    int firstUniqChar(string s) {
       int freq [26] {0};
       vector<pair<char, int>> present;
       for(int i = 0; i < s.length(); i++)
       {
            char c = s[i];
            int x = c - 'a';
            if (freq[x] == 0)
                present.push_back(make_pair(c, i));
            freq[x]++;
       } 
       for (int i = 0; i < present.size(); i++)
       {
            if (freq[present[i].first - 'a'] == 1)
                return present[i].second;
       }
       return -1;
    }
};