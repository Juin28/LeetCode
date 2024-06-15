class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int len = nums.size();
       int threshold = len/2;

       sort(nums.begin(), nums.end());

       for(int i = 1; i < len; i++)
       {
            int cnt = 1;
            while(nums[i] == nums[i-1])
            {
                cnt++;
                if (cnt > threshold)
                    return nums[i];
                i++;
            }
       }
       return nums[0];
    }
};