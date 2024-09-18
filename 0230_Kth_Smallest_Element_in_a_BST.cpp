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

// Recursive Solution
// class Solution {
// public:
//     void inOrderTraversal(TreeNode* root, int& cnt, int& ans, int k) {
//         if (!root)
//             return;
        
//         inOrderTraversal(root->left, cnt, ans, k);
//         cnt++;
//         if (cnt == k)
//         {
//             ans = root->val;
//             return;
//         }
//         inOrderTraversal(root->right, cnt, ans, k);

//     }
//     int kthSmallest(TreeNode* root, int k) {
//         int cnt = 0;
//         int ans = 0;
//         inOrderTraversal(root, cnt, ans, k);
//         return ans;     
//     }
// };

// Stack Solution
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* cur = root;

        while (!stack.empty() || cur)
        {
            while (cur)
            {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            k--;
            if (k == 0)
            {
                return cur->val;
            }
            cur = cur->right;
        }

        return 0;
    }
};
