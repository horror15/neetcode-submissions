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
    int sum = INT_MIN;
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int val =  max(root->val,max(root->val+left,root->val+right));
        sum = max(sum, max(val,root->val+left+right));
        return val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
