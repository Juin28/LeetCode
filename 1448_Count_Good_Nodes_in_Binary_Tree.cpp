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
    void dfs(TreeNode* root, int& cnt, int mx) {
        if (!root)
            return;
        
        if (mx <= root->val)
            cnt++;
        
        mx = max(root->val, mx);

        dfs(root->left, cnt, mx);
        dfs(root->right, cnt, mx);
    }
    
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt, root->val);

        return cnt;
    }
};
