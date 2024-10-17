class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;

        vector<int> blackIndex;
        vector<int> whiteIndex;
        
        long long blackCount = 0;

        for (char c : s) {
            if (c == '0') {
                blackCount++;
            }
        }

        for (int i = 0; i < blackCount; ++i) {
            if (s[i] == '1') {
                whiteIndex.push_back(i);
            }
        }
        for (int i = blackCount; i < s.length(); ++i) {
            if (s[i] == '0') {
                blackIndex.push_back(i);
            }
        }
        
        for (int i = 0; i < blackIndex.size(); ++i) {
            count += blackIndex[i] - whiteIndex[i];
        }

        return count;
    }
};