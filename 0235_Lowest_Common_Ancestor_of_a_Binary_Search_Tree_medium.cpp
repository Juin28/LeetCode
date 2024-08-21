/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive Solution
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (p->val > q->val)
//             swap(p, q);

//         if (root->val >= p->val && root->val <= q->val)
//             return root;
//         else if (root->val > p->val && root->val > q->val)
//             return lowestCommonAncestor(root->left, p, q);

//         return lowestCommonAncestor(root->right, p, q);
//     }
// };

// Optimal Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) 
        {
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
    }
};