// BRUTE FORCE SOLUTION

// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<int> num_edges (n+2, 0);

//         for (auto e: edges)
//         {
//             ++num_edges[e[0]];
//             ++num_edges[e[1]];
//         }
        
//         for(int i = 0; i < num_edges.size(); ++i) 
//         {
//             if (num_edges[i] == n)
//                 return i;
//         }
//         return 0;
//     }
// };


// OPTIMAL SOLUTION

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>& first = edges[0];
        vector<int>& second = edges[1];

        if (first[0] == second[0] || first[0] == second[1])
            return first[0];
        return first[1];
    }
};