class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";

        int spacesIndex = 0;
        int stringIndex = 0;
        int stringLen = s.length();
        int spacesLen = spaces.size();
        for (int spacesIndex = 0; spacesIndex < spacesLen; ++spacesIndex) {
            int space = spaces[spacesIndex];
            while (stringIndex < space && stringIndex < stringLen) {
                result.push_back(s[stringIndex]);
                ++stringIndex;
            }
            result.push_back(' ');
        }
        
        while (stringIndex < stringLen) {
            result.push_back(s[stringIndex]);
            ++stringIndex;
        }

        return result;
    }
};

