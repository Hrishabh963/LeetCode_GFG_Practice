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
    void helper(TreeNode* root,long long int sum,int target,int &ans){
        if(!root)return;
        sum+=root->val;
        if(sum == target)
            ans++;
        helper(root->left,sum,target,ans);
        helper(root->right,sum,target,ans);
    }
    void dfs(TreeNode* root,int target,int &ans){
        if(!root)return;
        long long int sum  = 0;
        helper(root,sum,target,ans);
        dfs(root->left,target,ans);
        dfs(root->right,target,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        dfs(root,targetSum,ans);
        return ans;
        
    }
};