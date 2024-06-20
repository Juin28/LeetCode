class Solution {
public:
    bool isPalindrome(string word) {
        int l = 0;
        int r = word.length() - 1;

        while(l < r)
        {
            if (word[l] == word[r]) 
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }
};