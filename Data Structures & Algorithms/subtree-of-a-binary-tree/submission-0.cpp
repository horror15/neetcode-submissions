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
    bool ismatch(TreeNode* root, TreeNode* subRoot){
        if (root == NULL && subRoot == NULL){
            return true;
        }
        if (root && subRoot && root->val == subRoot->val){
            bool left =  ismatch(root->left, subRoot->left);
            bool right =  ismatch(root->right, subRoot->right);
            return left && right;            
        }
        else{
            return false;
        }

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (root->val == subRoot->val) {
            if (ismatch(root, subRoot)){
                return true;
            }
        }
        bool left =  isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
};
