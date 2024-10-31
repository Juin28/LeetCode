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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        } else if (!root1 || !root2) {
            return false;
        }

        bool sameValue = (root1->val == root2->val);
        bool needSwap = false;

        if (root1->left && root2->left) {
            if (root1->left->val != root2->left->val) {
                needSwap = true;
            }
        } else if (root1->left || root2->left) {
            needSwap = true;
        }

        if (needSwap) {
            return sameValue && flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        }

        return sameValue && flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    }
};

