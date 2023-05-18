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
    // O(n^2) solution 
    // void helper(TreeNode* root,long long int sum,int target,int &ans){
    //     if(!root)return;
    //     sum+=root->val;
    //     if(sum == target)
    //         ans++;
    //     helper(root->left,sum,target,ans);
    //     helper(root->right,sum,target,ans);
    // }
    // void dfs(TreeNode* root,int target,int &ans){
    //     if(!root)return;
    //     long long int sum  = 0;
    //     helper(root,sum,target,ans);
    //     dfs(root->left,target,ans);
    //     dfs(root->right,target,ans);
    // }
    int ans = 0;
    void dfs(TreeNode* root,long long int sum,int target,unordered_map<long long int,int> &m){
        if(!root) return;
        sum+=root->val;
        if(sum == target) ans++;
        if(m.find(sum - target)!=m.end()){
            ans+= m[sum-target];
        }
        m[sum]++;
        dfs(root->left,sum,target,m);
        dfs(root->right,sum,target,m);
        m[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        //we can use map to store the current path sum,use count subarray sum logic to count the path sums
        unordered_map<long long int,int> m;
        dfs(root,0,targetSum,m);
        return ans;
        
    }
};