class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       vector<int> check (1001, false); 
       vector<int> ans;

       for (int i = 0; i < nums1.size(); ++i) 
       {
            ++check[nums1[i]];
       }

       for (int i = 0; i < nums2.size(); ++i) 
       {
            if (check[nums2[i]])
            {
                ans.push_back(nums2[i]);
                --check[nums2[i]];
            }
       }

       return ans;
    }
};