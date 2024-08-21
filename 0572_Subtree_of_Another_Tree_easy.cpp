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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;
            
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        return (left && right && p->val == q->val);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;
        
        if (!root)
            return false;
        
        bool leftSame = isSameTree(root->left, subRoot->left);
        bool rightSame = isSameTree(root->right, subRoot->right);
        if (root->val == subRoot->val && leftSame && rightSame)
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
