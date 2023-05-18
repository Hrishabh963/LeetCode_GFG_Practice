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
    void dfs(TreeNode* node,vector<int> &arr){
        if(!node) return;
        if(!node->left && !node->right) arr.push_back(node->val);
        dfs(node->left,arr);
        dfs(node->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>vec1,vec2;
        dfs(root1,vec1);
        dfs(root2,vec2);
        return vec1==vec2;
    }
};