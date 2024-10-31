class MedianFinder {
private:
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int> > largeHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int smallSize = smallHeap.size();
        int largeSize = largeHeap.size();
        
        if (smallSize && largeSize) {
            int largestInSmall = smallHeap.top();
            int smallestInLarge = largeHeap.top();

            if (num < largestInSmall) {
                smallHeap.push(num);
            } else {
                largeHeap.push(num);
            }
        } else if (largeSize) {
            int smallestInLarge = largeHeap.top();
            
            if (num <= smallestInLarge) {
                smallHeap.push(num);
            } else {
                largeHeap.push(num);
            }
        } else if (smallSize) {
            int largestInSmall = smallHeap.top();
            
            if (num >= largestInSmall) {
                largeHeap.push(num);
            } else {
                smallHeap.push(num);
            }
        } else {
            largeHeap.push(num);
        }

        if (smallHeap.size() > largeHeap.size()) {
            int largestInSmall = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(largestInSmall);
        } else if (smallHeap.size() < largeHeap.size() - 1) {
            int smallestInLarge = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(smallestInLarge);
        }
        
    }
    
    double findMedian() {
        int totalNum = smallHeap.size() + largeHeap.size();

        if (totalNum % 2 == 0) {
            double largestInSmall = smallHeap.top();
            double smallestInLarge = largeHeap.top();
            return (largestInSmall + smallestInLarge) / 2.00;
        } else {
            return largeHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

