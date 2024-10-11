class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, vector<int> > > maxHeap;

        for (vector<int>& point : points) {
            int distance = point[0]*point[0] + point[1]*point[1];
            maxHeap.push({distance, {point[0], point[1]}});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> kClosestPoints;
        while(!maxHeap.empty()) {
            kClosestPoints.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return kClosestPoints;
    }
};

// Sorting Solution
// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         if (k >= points.size() )
//             return points;
        
//         vector< pair<int, int> > cal;
//         vector<vector<int>> ans;
        
//         for (int i = 0; i < points.size(); i++)
//         {
//             int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
//             cal.push_back(make_pair(dist, i));
//         }
        
//         sort(cal.begin(), cal.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
//             return a.first < b.first;
//         });
        
//         for (int j = 0; j < k; j++)
//         {
//             ans.push_back(points[cal[j].second]);
//         }
        
//         return ans;
//     }
// };