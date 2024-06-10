class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int check_1 [128];
        int check_2 [128];
        
        for (int i = 0; i < s.length(); i++)
        {
            if (check_1[s[i]] != check_2[t[i]])
                return false;

            check_1[s[i]] = i + 1;
            check_2[t[i]] = i + 1;
        }

        return true;        
    }
};
