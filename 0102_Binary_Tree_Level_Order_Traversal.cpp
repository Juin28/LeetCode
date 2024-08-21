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
//     void dfs(TreeNode* root, vector<vector<int>>& levels, int cur ) {
//         if (!root)
//             return;
        
//         if (cur >= levels.size())
//         {
//             levels.push_back({root->val});
//         }
//         else
//         {
//             levels[cur].push_back(root->val);
//         }

//         dfs(root->left, levels, cur + 1);
//         dfs(root->right, levels, cur + 1);
//     }

//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> levels;
//         dfs(root, levels, 0);

//         return levels;
//     }
// };

// Optimal Solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        deque<TreeNode*> sameLevelNodes;
        int cnt = 0;

        if (root)
            sameLevelNodes.push_back(root);
        
        while(!sameLevelNodes.empty())
        {
            levels.push_back({});
            int siz = sameLevelNodes.size();

            for (int i = 0; i < siz; ++i)
            {
                TreeNode* node = sameLevelNodes.front();
                sameLevelNodes.pop_front();
                levels[cnt].push_back(node->val);
                
                if(node->left)
                    sameLevelNodes.push_back(node->left);
                if(node->right)
                    sameLevelNodes.push_back(node->right);
            }

            ++cnt;
        }

        return levels;
    }
};
