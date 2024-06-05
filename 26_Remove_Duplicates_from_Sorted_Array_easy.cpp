class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        int k = 1;
        int temp = nums[0];
        vector<int>::iterator p1 = nums.begin() + 1;
        vector<int>::iterator p2 = nums.begin() + 1;


        for (; p2 < nums.end(); p2++)
        {
            if (*p2 != temp)
            {
                if (p1 != p2)
                {
                    *p1 = *p2;  
                }
                k++;
                p1++;
                temp = *p2;
            }
        }
        return k;
    }
};