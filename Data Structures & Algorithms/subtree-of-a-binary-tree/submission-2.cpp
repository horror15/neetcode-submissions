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
    bool issub(TreeNode* root, TreeNode* subRoot){
        if(root && subRoot){
            if(root->val == subRoot->val){
                return issub(root->right, subRoot->right) && issub(root->left, subRoot->left);
            } else {
                return false;
            }
        } else if(!root && !subRoot){
            return true;
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root){
            if(root->val == subRoot->val && issub(root, subRoot)){
                return true;
            } else {
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            }
        } else {
            return false;
        } 
    }
};
