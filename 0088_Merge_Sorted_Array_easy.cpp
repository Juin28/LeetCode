class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        else if (m == 0)
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                nums1[i] = nums2[i]; 
            }
            return;
        }

        int p1 = 0;
        int p2 = 0;

        while (p1 < m && m != nums1.size())
        {
            if (nums1[p1] >= nums2[p2])
            {
                nums1.insert(nums1.begin() + p1, nums2[p2++]);
                nums1.pop_back();
                m++;
            }
            else
            {
                p1++;
            }
        }

        while (p2 < n)
        {
            nums1[p1++] = nums2[p2++];
        }
    }
};