class Solution {
public:
    int trap(std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int left_max = height[0];
        int right_max = height[r];
        int water = 0;

        while (l < r) 
        {
            if (left_max <= right_max) 
            {
                int change = (left_max > height[l]) ? left_max - height[l] : 0 ;
                water += change;
                ++l;
                left_max = max(left_max, height[l]);
            } 
            else 
            {
                int change = (right_max > height[r]) ? right_max - height[r] : 0 ;
                water += change;
                --r;
                right_max = max(right_max, height[r]);
            }
        }
        return water;
    }
};