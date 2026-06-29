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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*>q;
        string str = "";
        if (!root){
            return str;
        }
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node==nullptr){
                str +=  "#,";
            } else{
                str += to_string(node->val) + ","; 
                q.push(node->left);
                q.push(node->right);
            }
            q.pop();          
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        stringstream ss(data);
        string item;
        queue<TreeNode*>q;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        q.push(root);
        while(!q.empty()){
            TreeNode* root = q.front();
            getline(ss, item, ',');
            if (item != "#"){
                TreeNode* node = new TreeNode(stoi(item));
                root->left = node; 
                q.push(node);
            } else{
                root->left = nullptr;
            }
            getline(ss, item, ',');
            if (item != "#"){
                TreeNode* node = new TreeNode(stoi(item));
                root->right = node; 
                q.push(node);
            } else{
                root->right = nullptr;
            }
            
            q.pop();
        }
        return root;

    }
};
