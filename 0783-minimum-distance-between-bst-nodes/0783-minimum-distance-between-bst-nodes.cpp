class Solution {
public:
    void helper(TreeNode* root, vector<int>& storeNodeVal) {
        if(root == nullptr)
            return;
        helper(root -> left, storeNodeVal);
        storeNodeVal.push_back(root -> val);
        helper(root -> right, storeNodeVal);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> storeNodeVal;
        helper(root, storeNodeVal);
        int minDiff = INT_MAX;
        for (int i = 0; i < storeNodeVal.size()-1; i++) {
            minDiff = min(minDiff, storeNodeVal[i+1] - storeNodeVal[i]);
        }
        return minDiff;
    }
};