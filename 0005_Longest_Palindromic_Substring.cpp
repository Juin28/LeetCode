// Time: O(n^2), Memory: O(1)
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (s.empty())
//             return "";
        
//         string ans = "";
//         int max_length = 0;

//         for(int i = 0; i < s.length(); i++)
//         {
//             int lp = i, rp = i;
//             while ( (lp >= 0) && (rp < s.length()) && (s[lp] == s[rp]) )
//             {
//                 if (rp - lp + 1 > max_length)
//                 {
//                     max_length = rp - lp + 1;
//                     ans = s.substr(lp, rp - lp + 1);
//                 }
//                 lp--;
//                 rp++;
//             }

//             lp = i, rp = i + 1;
//             while ( (lp >= 0) && (rp < s.length()) && (s[lp] == s[rp]) )
//             {
//                 if (rp - lp + 1 > max_length)
//                 {
//                     max_length = rp - lp + 1;
//                     ans = s.substr(lp, rp - lp + 1);
//                 }
//                 lp--;
//                 rp++;
//                 }
//         }
//         if (ans.empty())
//             ans.push_back(s[0]);
//         return ans;
//     }
// };

// Time: O(n^2), Memory: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();

        if (len <= 1) {
            return s;
        }

        int start = 0;
        int end = 1;
        int maxSubstringLength = 1;

        vector<vector <bool> > dp (len, vector<bool> (len, false));

        for (int i = 0; i < len; ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                int substringLength = i - j + 1;
                if (s[j] == s[i] && (substringLength == 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (substringLength > maxSubstringLength) {
                        maxSubstringLength = substringLength;
                        start = j;
                        end = i; 
                    }
                }
            }
        }

        return s.substr(start, maxSubstringLength);
    }
};

// Brute Force Solution
// class Solution {
// public:
//     bool isPalindrome (string s) {
//         int left = 0;
//         int right = s.length() - 1;

//         while (left < right) {
//             if (s[left] != s[right]) {
//                 return false;
//             }
//             left++;
//             right--;
//         }

//         return true;
//     }
    
//     string longestPalindrome(string s) {
//         int len = s.length();

//         if (len == 1) {
//             return s;
//         }

//         if (isPalindrome(s)) {
//             return s;
//         } else {
//             string leftPalindrome = longestPalindrome(s.substr(0, len - 1));
//             string rightPalindrome = longestPalindrome(s.substr(1, len - 1));

//             return (leftPalindrome.length() > rightPalindrome.length()) ? leftPalindrome : rightPalindrome;
//         }
//     }
// };
