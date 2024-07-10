// // O(n log n)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int s_len = s.length();
//         int t_len = t.length();

//         if (s_len != t_len)
//             return false;
        
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         for(int i = 0; i < s_len; ++i)
//         {
//             if (s[i] != t[i])
//                 return false;
//         }
//         return true;
//     }
// };

// O(n) 
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> c_cnt;
        for (const char& c : s) 
            ++c_cnt[c];
        

        for (const char& c : t) 
         {
            if (c_cnt.count(c)) 
            {
                if (c_cnt[c] == 1) 
                    c_cnt.erase(c);
                else 
                    --c_cnt[c];
                
            } 
            else 
                return false;
            
        }

        return c_cnt.empty();
    }
};