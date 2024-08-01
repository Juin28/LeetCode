class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int final_rate = 0;

        while(l <= r)
        {
            double rate = (l + r) >> 1;
            unsigned long time = 0;
            for (int i : piles)
                time += ceil(static_cast<double>(i) / rate);
            if (time <= h)
            // Can't separate == and < cases as == might use a rate larger than minimum rate
            {
                final_rate = rate;
                r = rate - 1;
            }
            else
                l = rate + 1;
        }

        return final_rate;
    }
};
