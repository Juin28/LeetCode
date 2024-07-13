// O(n log n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int, int> > get_idx;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            get_idx.push_back(make_pair(nums[i], i));
        }
        sort(get_idx.begin(), get_idx.end());
        int l = 0;
        int r = n - 1;

        while (l < r) 
        {
            int sum = get_idx[l].first + get_idx[r].first;
            cout << "l = " << l << "\tr = " << r << "\tsum = " << sum << endl;
            if (sum == target)
            {
                int smaller = get_idx[l].second;
                int larger = get_idx[r].second;
                if (smaller > larger)
                    swap(smaller, larger);
                return vector<int> {smaller, larger};
            }
            else if (sum < target)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }

        return vector<int> {l, r};
    }
};


// O(n^2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> x = {};
//         for(int i = 0; i < nums.size() -1; i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 if( (nums.at(i) + nums.at(j)) == target){
//                     x.push_back(i);
//                     x.push_back(j);
//                     // return x;
//                 }
//             }
//         }
//         return x;
//     }
// };
