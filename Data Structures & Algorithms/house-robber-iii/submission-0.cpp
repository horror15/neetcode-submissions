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
    pair<int, int> dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);   
        int rob = root->val +  l.second + r.second;
        int NotRob = max(l.first, l.second) + max(r.first, r.second);
        return {rob, NotRob};           
    }
    int rob(TreeNode* root) {
        pair<int, int>p;
        p = dfs(root);
        return max(p.first, p.second);
    }
};