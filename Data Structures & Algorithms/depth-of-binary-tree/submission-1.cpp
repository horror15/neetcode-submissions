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
    int dfs(TreeNode* root, int height){
        if(!root){
            return 0;
        }
        height = 1 + max(dfs(root->left, height),dfs(root->right, height));
        return height;

    }
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};
