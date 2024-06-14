class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool freq [46] {false};
        sort(arr.begin(), arr.end());
        int len = arr.size();

        // [-3,-3,-3,0,0,1,1,1,1,10]
        for (int i = 0; i < len; i++)
        {
            int cnt = 1;
            while(i != (len-1) && arr[i] == arr[i+1])
            {
                if (cnt < 45)
                    cnt++;
                i++;
            }
            if (freq[cnt])
                return false;
            freq[cnt] = true;
        }
        
        return true;
    }
};