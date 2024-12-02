class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int sentenceLen = sentence.length();
        int searchWordLen = searchWord.length();
        int prefixIndex = 1;
        int sentenceIndex = 0;

        while (sentenceIndex < sentenceLen) {
            int searchWordIndex = 0;

            while (sentenceIndex < sentenceLen && searchWordIndex < searchWordLen && sentence[sentenceIndex] == searchWord[searchWordIndex]) {
                ++sentenceIndex;
                ++searchWordIndex;
            }

            if (searchWordIndex == searchWordLen) {
                return prefixIndex;
            }

            while (sentenceIndex < sentenceLen && sentence[sentenceIndex] != ' ') {
                ++sentenceIndex;
            }
            ++sentenceIndex;
            ++prefixIndex;
        }


        return -1;
    }
};

