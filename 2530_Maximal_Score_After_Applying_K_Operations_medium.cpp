class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> maxHeap (nums.begin(), nums.end());

        for (int i = 0; i < k; ++i) {
            int maxNum = maxHeap.top();
            maxHeap.pop();
            score += maxNum;
            int newNum = ceil(static_cast<double>(maxNum) / 3);
            maxHeap.push(newNum);
        }

        return score;
    }
};
