class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        int len = s1.length();
        vector< pair<char, char> > diff;

        for (int i = 0; i < len; ++i) {
            if (s1[i] != s2[i]) {
                diff.push_back({s1[i], s2[i]});
            }
        }

        if (diff.size() != 2) {
            return false;
        }

        return (diff[0].first == diff[1].second) && (diff[0].second == diff[1].first);
    }
};
