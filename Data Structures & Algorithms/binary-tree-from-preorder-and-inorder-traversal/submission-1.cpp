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
    TreeNode* dfs(vector<int>& preorder, int rootI, int left, int right, unordered_map<int, int>&mp){
        int mid = mp[preorder[rootI]];
        TreeNode* root = new TreeNode(preorder[rootI]);
        if(mid>left){
            root->left = dfs(preorder, rootI+1, left, mid-1, mp);
        }
        if(mid<right){
            root->right = dfs(preorder, rootI+(mid-left+1), mid+1, right, mp);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return dfs(preorder, 0, 0, preorder.size()-1, mp);
    }
};
