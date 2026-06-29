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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL){
            return NULL;
        }
        if(root->val == key){
            if (root->left == NULL){
                return root->right;
            } else if(root->right == NULL){
                return root->left;
            } else {
                TreeNode* newnode = root->right;
                while (newnode->left){
                    newnode = newnode->left;
                }
                root->val = newnode->val;
                root->right = deleteNode(root->right, newnode->val);

            }                   
        }
        if (root->val > key){
            root->left = deleteNode(root->left, key);
        } 
        if (root->val < key){
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};