class Solution {
public:
    string smallestNumber(string pattern) {
        int currentNum = 2;
        int numsOfD = 0;
        string result = "1";

        for (char p : pattern) {
            if (p == 'I') {
                numsOfD = 0;
                char addedNum = static_cast<char>(currentNum + '0');
                result.push_back(addedNum);
                ++currentNum;
            } else if (p == 'D') {
                ++numsOfD;
                string tempEndOfResult = "";
                for (int i = 0; i < numsOfD; ++i) {
                    tempEndOfResult.push_back(result.back());
                    result.pop_back();
                }
                char addedNum = static_cast<char>(currentNum + '0');
                result.push_back(addedNum);
                for (int i = 0; i < numsOfD; ++i) {
                    result.push_back(tempEndOfResult.back());
                    tempEndOfResult.pop_back();
                }
                ++currentNum;
            }
        }

        return result;
    }
};

