class Solution {
public:
    bool isSubstring(string& substring, string& word) {
        int substringLen = substring.length();
        int wordLen = word.length();
        int substringIndex = 0;
        int wordIndex = 0;

        while (wordIndex < wordLen) {
            int tmpWordIndex = wordIndex;
            while (substring[substringIndex] == word[tmpWordIndex]) {
                ++substringIndex;
                ++tmpWordIndex;

                if (substringIndex == substringLen) {
                    return true;
                }
            }
            substringIndex = 0;
            ++wordIndex;
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> results;

        for (int i = 0; i < n; ++i) {
            string& substring = words[i];
            for (int j = 0; j < n; ++j) {
                string& word = words[j];
                if (j == i || substring.length() > word.length()) {
                    continue;
                }

                if (isSubstring(substring, word)) {
                    results.push_back(substring);
                    break;
                }
            }
        }

        return results;
    }
};

