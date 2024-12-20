class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue <int> maxHeap (piles.begin(), piles.end());
        long long numStone = 0;

        for (int i = 0; i < k; ++i) {
            int newPile = maxHeap.top() - static_cast<int> (maxHeap.top()/2);
            maxHeap.pop();
            maxHeap.push(newPile);
        }

        while (!maxHeap.empty()) {
            numStone += maxHeap.top();
            maxHeap.pop();
        }

        return numStone;
    }
};
