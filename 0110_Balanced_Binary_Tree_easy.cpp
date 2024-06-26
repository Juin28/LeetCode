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
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        else if (!root->left && !root->right)
            return 1;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        bool check = abs(depth(root->left) - depth(root->right)) <= 1;
        return (check && isBalanced(root->left) && isBalanced(root->right));
    }
};