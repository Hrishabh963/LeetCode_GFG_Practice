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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int target, vector<int> arr){
        if(!root)return;
        if(root->val == target && !root->left && !root->right){
            arr.push_back(root->val);
            ans.push_back(arr);
            return;
        }
        arr.push_back(root->val);
        dfs(root->left,target - root->val,arr);
        dfs(root->right,target - root->val,arr);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> arr;
        dfs(root,targetSum,arr);
        return ans;
    }
};