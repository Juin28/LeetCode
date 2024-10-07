class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create a maxHeap and pop the two heaviest stones everytime and compare
        // If there is remaining one, push back to the maxHeap
        // Else, continue until the size <= 1
        priority_queue<int> maxHeap (stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int heavier = maxHeap.top();
            maxHeap.pop();
            int lighter = maxHeap.top();
            maxHeap.pop();

            if (heavier > lighter) {
                maxHeap.push(heavier - lighter);
            }
        }

        return (maxHeap.size() == 0) ? 0 : maxHeap.top();
    }
};
