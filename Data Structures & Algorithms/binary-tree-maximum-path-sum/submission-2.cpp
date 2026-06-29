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
        if (!root){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int data = max(left+right+root->val, max(left, right)+root->val);
        sum = max(sum, max(data, root->val));
        return max(max(left, right)+root->val, root->val);

    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
