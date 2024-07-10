class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        
        for (const string& c: logs)
        {
            if (c == "../")
            {
                if (cnt > 0) 
                    --cnt;
            }
            else if (c != "./")
                ++cnt;
        }

        return cnt;
    }
};