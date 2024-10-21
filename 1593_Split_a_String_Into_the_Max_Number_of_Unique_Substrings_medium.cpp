class Solution {
public:
    int backtrack(int start, string s, unordered_set<string>& seen) {
        if (start == s.length()) {
            return 0;
        }

        int maxSplits = 0;

        for (int end = start + 1; end <= s.length(); end++) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSplits = max(maxSplits, 1 + backtrack(end, s, seen));
                seen.erase(substring);
            }
        }
        return maxSplits;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
};

