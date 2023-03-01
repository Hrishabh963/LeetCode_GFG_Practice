/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#";
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserializeUtil(istringstream &str){
        string s;
        str>>s;
        if(s=="#")return NULL;
        TreeNode* ans = new TreeNode(stoi(s));
        ans->left = deserializeUtil(str);
        ans->right = deserializeUtil(str);
        return ans;
    }
    
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return deserializeUtil(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));