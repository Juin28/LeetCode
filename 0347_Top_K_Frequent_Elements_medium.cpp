class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> cnt;
        vector< vector<int> > freq (nums.size() + 1);
        vector<int> top_k;

        for (const int& i : nums)
        {
            ++cnt[i];
        }

        for (const auto& i : cnt)
        {
            freq[i.second].push_back(i.first);
        }

        for (int i = freq.size() - 1; i > 0; --i)
        {
            for (const int& j : freq[i])
            {
                top_k.push_back(j);
                if (top_k.size() == k)
                    return top_k;
            }
        }
        
        return top_k;
    }
};