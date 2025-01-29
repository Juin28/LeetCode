class Solution {
public:
    bool hasCycleDFS (vector<vector<int>>& neighbours, vector<bool>& visited, int node, int parent) {
        visited[node] = true;

        for (int neighbour : neighbours[node]) {
            if (!visited[neighbour]) {
                if (hasCycleDFS(neighbours, visited, neighbour, node)) {
                    return true;
                } 
            } else if (neighbour != parent) {
                return true;
            }
        }

        return false;
    }

    bool hasCycle(vector<vector<int>>& neighbours, int n) {
        vector<bool> visited (n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            if (neighbours[i].empty() || visited[i]) {
                continue;
            }

            if (hasCycleDFS(neighbours, visited, i, -1)) {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> neighbours (n + 1);

        for (vector<int>& edge : edges) {
            int nodeOne = edge[0];
            int nodeTwo = edge[1];

            neighbours[nodeOne].push_back(nodeTwo);
            neighbours[nodeTwo].push_back(nodeOne);

            if (hasCycle(neighbours, n)) {
                return edge;
            }
        }

        return {};
    }
};

