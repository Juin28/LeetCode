class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        sort(allowed.begin(), allowed.end());
        for(string& s : words)
        {
            sort(s.begin(), s.end());
        }

        int max_iter = allowed.length();
        int cnt = 0;

        for(const string& s : words)
        {
            int p1 = 0;
            int p2 = 0;
            bool consistent = true;

            for (; p2 < s.length(); ++p2)
            {
                if (s[p2] == allowed[p1])
                    continue;
                
                if (s[p2] != allowed[p1])
                {
                    bool present = false;
                    ++p1;
                    while (p1 <= max_iter)
                    {
                        if (s[p2] == allowed[p1])
                        {
                            present = true;
                            break;
                        }
                        else
                        {
                            ++p1;
                        }
                    }
                    
                    if (!present)
                    {
                        consistent = false;
                        break;
                    }
                }
                
            }

            if (consistent)
                ++cnt;
        }

        return cnt;
    }
};
