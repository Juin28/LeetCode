class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return {};
        }
        
        unordered_map<int, int> numToRank;
        vector<int> ranks;

        vector<int> arrCopy (arr);
        sort(arrCopy.begin(), arrCopy.end());
        int rank = 1;
        numToRank[arrCopy[0]] = 1;
        for (int i = 1; i < arrCopy.size(); ++i) {
            if (arrCopy[i] > arrCopy[i - 1]) {
                ++rank;
            }
            numToRank[arrCopy[i]] = rank;
        }

        for (int i : arr) {
            ranks.push_back(numToRank[i]);
        }

        return ranks;
    }
};

