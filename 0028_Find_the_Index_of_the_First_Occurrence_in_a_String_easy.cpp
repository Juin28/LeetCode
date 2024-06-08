class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
            return -1;
            
        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                int hp = i + 1;
                bool match = true;
                for (int np = 1; np < needle.size(); np++, hp++)
                {
                    if (haystack[hp] != needle[np])
                    {
                        match = false;
                        break;
                    }
                }
                if (match)
                    return i;
            }   
        }
        return -1;    
    }
};