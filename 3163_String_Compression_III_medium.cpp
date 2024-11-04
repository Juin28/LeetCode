class Solution {
public:
    string compressedString(string word) {
        string compressed = "";

        int wordLen = word.length();
        int wordPointer = 0;

        if (wordLen == 0) {
            return "";
        }

        int charCount = 0;
        char charCurrent = ' ';

        while (wordPointer < wordLen) {
            if (word[wordPointer] == charCurrent && charCount < 9) {
                charCount++;
            } else {
                if (wordPointer != 0) {
                    compressed += to_string(charCount);
                    compressed.push_back(charCurrent);
                }
                charCount = 1;
                charCurrent = word[wordPointer];
            }
            wordPointer++;
        }
        compressed += to_string(charCount);
        compressed.push_back(charCurrent);

        return compressed;
    }
};
