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

class Codec {
public:
    string s = "";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return s;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size){
                TreeNode* node = q.front();
                q.pop();
                if(!node){
                    s+="N,";
                } else {
                    q.push(node->left);
                    q.push(node->right);
                    s+=to_string(node->val)+",";
                }
                size--;
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        queue<TreeNode*>q;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(getline(ss, val, ',')){
                if(val!="N"){
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }
            if(getline(ss, val, ',')){
                if(val!="N"){
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
