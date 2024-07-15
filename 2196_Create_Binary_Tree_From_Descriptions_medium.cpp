/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        const int N = 100001;
        bitset<N> seen = 0;
        int root = -1;
        int parent[N] = {0};
        TreeNode* node[N] = {nullptr};

        for(const auto& des : descriptions)
        {
            int parent_val = des[0], child_val = des[1], left = des[2];

            if (!seen[parent_val])
            {
                node[parent_val] = new TreeNode(parent_val);
                seen[parent_val] = 1;
                if (!parent[parent_val])
                    root = parent_val;
            }
            if (!seen[child_val])
            {
                node[child_val] = new TreeNode(child_val);
                seen[child_val] = 1;
            }

            parent[child_val] = parent_val;

            if (left)
                node[parent_val]->left = node[child_val];
            else
                node[parent_val]->right = node[child_val];
        }

        while (parent[root] != 0)
            root = parent[root];

        return node[root];
    }
};