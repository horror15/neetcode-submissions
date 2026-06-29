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
    TreeNode* FindNode(TreeNode* node, TreeNode* &newnode){
        if(node->left == NULL){
            newnode = node;
            return node->right;
        }
        node->left =  FindNode(node->left, newnode);
        return node;
    }
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
                TreeNode* newnode = NULL;
                TreeNode* tmp = FindNode(root->right, newnode);
                newnode->right = tmp;
                newnode->left = root->left;
                delete root;
                return newnode;
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