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
    void dfs(vector<int>& rightNodes, TreeNode* root, int depth) {
        if (!root)
            return;
        
        if (depth >= rightNodes.size())
        {
            rightNodes.push_back(root->val);
        }
        else
        {
            rightNodes[depth] = root->val;
        }

        dfs(rightNodes, root->left, depth + 1);
        dfs(rightNodes, root->right, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNodes;
        dfs(rightNodes, root, 0);

        return rightNodes;
    }
};
