class Solution {
public:
    int minimumPushes(string word) {
        int numOfDistinctChar = 0;
        vector<pair<int, char>> count (26);
        int numOfPushes = 0;

        for (int i = 0; i < 26; ++i)
            count[i] = {0, static_cast<char>(i + 'a')};

        for (char a : word)
        {
            if (count[a - 'a'].first == 0)
                numOfDistinctChar++;
            count[a - 'a'].first++;
        }

        if (numOfDistinctChar <= 7)
            return word.length();
        

        sort(count.begin(), count.end(), [&](pair<int, char>& a, pair<int, char>& b){
            return a.first > b.first;
        });

        int push = 1;
        int tmp = 0;
        for (int i = 0; i < 26; ++i, ++tmp)
        {
            if (tmp > 7)
            {    
                ++push;
                tmp = 0;
            }
            numOfPushes += count[i].first * push;
        }

        return numOfPushes;
    }
};