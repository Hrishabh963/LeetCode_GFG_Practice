/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* getRoot(vector<int> &in, int inStart, int inEnd, vector<int> &post, int postStart, int postEnd, map< int, int> &m)
        {
            if (inStart > inEnd || postStart > postEnd) return NULL;
            TreeNode *root = new TreeNode(post[postEnd]);
            int inRoot = m[post[postEnd]];
            int numsOnLeft = inRoot - inStart;
            root->left = getRoot(in, inStart, inRoot - 1, post,postStart,postStart+numsOnLeft-1,m);
            root->right = getRoot(in,inRoot+1,inEnd,post,postStart+numsOnLeft,postEnd-1,m);
            return root;

        }
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        TreeNode *root = getRoot(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, m);
        return root;
    }
};