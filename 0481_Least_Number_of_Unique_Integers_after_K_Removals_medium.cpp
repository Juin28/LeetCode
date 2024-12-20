class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        vector<int> uniqueElements;
        vector<pair<int, int> > countAndNum;

        for (int i : arr) {
            if (count[i] == 0) {
                uniqueElements.push_back(i);
            } 
            ++count[i];
        }

        for (int i : uniqueElements) {
            countAndNum.push_back({count[i], i});
        }
        int numUniqueElements = uniqueElements.size();

        sort(countAndNum.begin(), countAndNum.end());

        for (pair<int, int>& p : countAndNum) {
            if (k >= p.first) {
                k -= p.first;
                numUniqueElements--;
            } else {
                return numUniqueElements;
            }
        }

        return 0;
    }
};

