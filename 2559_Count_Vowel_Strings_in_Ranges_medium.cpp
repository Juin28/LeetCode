class Solution {
public:
    bool isValid(string& word) {
        int len = word.length() - 1;

        bool start = (word[0] == 'a') || (word[0] == 'e') || (word[0] == 'i') || (word[0] == 'o') || (word[0] == 'u');
        bool end = (word[len] == 'a') || (word[len] == 'e') || (word[len] == 'i') || (word[len] == 'o') || (word[len] == 'u');

        return start && end;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> numValid (n + 1, 0);
        vector<int> results;

        for (int i = 0; i < n; ++i) {
            string& word = words[i];

            if (isValid(word)) {
                numValid[i + 1] = numValid[i] + 1;
            } else {
                numValid[i + 1] = numValid[i];
            }
        }

        for (vector<int>& query : queries) {
            int start = query[0];
            int end = query[1] + 1;

            int result = numValid[end] - numValid[start];

            results.push_back(result);
        }

        return results;
    }
};

