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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        if(!root){
            return vec;
        }
        queue<TreeNode*>q;
        int index = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp;
            while(size!=0){
                TreeNode* node = q.front();
                if(node->left){
                    q.push(node->left);
                } if (node->right){
                    q.push(node->right);
                }
                tmp.push_back(node->val);
                q.pop();
                size--;
            }
            vec.push_back(tmp);
            index++;
        }
        return vec;
    }
};
