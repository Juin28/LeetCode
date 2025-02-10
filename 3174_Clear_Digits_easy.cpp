// Optimal Approach
class Solution {
public:
    string clearDigits(string s) {
        string result = "";
        int len = s.length();

        for (int i = 0; i < len; ++i) {
            char currentChar = s[i];
            if (currentChar < '0' || currentChar > '9') {
                result.push_back(currentChar);
            } else {
                result.pop_back();
            }
        }

        return result;
    }
};

// Recursive Approach
// class Solution {
// public:
//     int digitAt(const string& s) {
//         int len = s.length();

//         for (int i = 0; i < len; ++i) {
//             if (s[i] >= '0' && s[i] <= '9') {
//                 return i;
//             }
//         }

//         return len;
//     }

//     string clearDigits(string s) {
//         int len = s.length();
//         int digitIndex = digitAt(s);

//         if (digitIndex == len) {
//             return s;
//         } else {
//             string newS = "";
//             if (digitIndex > 0) {
//                 newS += s.substr(0, digitIndex - 1);
//             }
//             newS += s.substr(digitIndex + 1);
//             return clearDigits(newS);
//         }
//     }
// };

