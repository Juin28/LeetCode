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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> left;
        vector<int> right;
        vector<int> combined;

        left = postorderTraversal(root->left);
        for (int i : left) {
            combined.push_back(i);
        }
        
        right = postorderTraversal(root->right);
        for (int i : right) {
            combined.push_back(i);
        }

        combined.push_back(root->val);
        return combined;
    }
};

