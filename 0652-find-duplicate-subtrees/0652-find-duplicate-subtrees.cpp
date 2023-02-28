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
    
    string rec(TreeNode* root,unordered_map<string,int> &m,vector<TreeNode*>& ans){
        if(!root)return "NULL";
        string left = rec(root->left,m,ans);
        string right = rec(root->right,m,ans);
        string s = to_string(root->val) + "," + left + "," + right;
        if(m[s] == 1) ans.push_back(root); //Duplicate found as it already exists in the hashmap
        m[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode*> ans;
        rec(root,m,ans);
        return ans;
    }
};