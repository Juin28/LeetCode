class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <int> maxHeap (gifts.begin(), gifts.end());
        long long numGifts = 0;

        for (int i = 0; i < k; ++i) {
            int newGift = sqrt(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(newGift);
        }

        while (!maxHeap.empty()) {
            numGifts += maxHeap.top();
            maxHeap.pop();
        }

        return numGifts;
    }
};
