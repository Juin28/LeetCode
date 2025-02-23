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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.length();
        int i = 0;
        int depth = 0;
        stack<TreeNode*> parents;

        int rootVal = 0;
        while (i < n && traversal[i] != '-') {
            rootVal *= 10;
            rootVal += static_cast<int>(traversal[i] - '0');
            ++i;
        }
        
        TreeNode* root = new TreeNode(rootVal);
        parents.push(root);

        while (i < n) {
            while (i < n && traversal[i] == '-') {
                ++depth;
                ++i;
            }

            int childrenVal = 0;
            while (i < n && traversal[i] != '-') {
                childrenVal *= 10;
                childrenVal += static_cast<int>(traversal[i] - '0');
                ++i;
            }

            while (parents.size() > depth) {
                parents.pop();
            }
            TreeNode* parent = parents.top();
            TreeNode* children = new TreeNode(childrenVal);

            if (!parent->left) {
                parent->left = children;
            } else {
                parent->right = children;
            }
            
            parents.push(children);
            depth = 0;
        }

        return root;
    }
};

