class Solution {
public:
    int maxArea(vector<int>& height) {

        if (height.size() < 2)
            return 0;
        if (height.size() == 2)
            return *min_element(height.begin(), height.end());

        int lp = 0;
        int rp = height.size() - 1;

        int max_water = 0;

        while (lp < rp)
        {
            int water = min(height[lp], height[rp]) * (rp - lp);
            if (water > max_water)
                max_water = water;

            if (height[rp] > height[lp])
                lp++;
            else
                rp--;   
        }
        return max_water; 
    }
};
