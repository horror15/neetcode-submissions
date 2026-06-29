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
    unordered_map<int, int>mp;
    TreeNode* dfs(vector<int> &preorder, vector<int>& inorder, int l, int r, int &preindex){
        if(l > r){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[preindex]);
        int index = mp[preorder[preindex]];
        preindex++;
        node->left = dfs(preorder, inorder, l, index-1, preindex);
        node->right = dfs(preorder, inorder, index+1, r, preindex);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int preindex = 0;
        return dfs(preorder, inorder, 0, inorder.size()-1, preindex);
    }
};
