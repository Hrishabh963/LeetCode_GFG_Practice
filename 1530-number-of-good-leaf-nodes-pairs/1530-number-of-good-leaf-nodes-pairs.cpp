class Solution {
public:
int countPairs(TreeNode* root, int distance) {
int res = 0;
dfs(root, distance, res);
return res;
}

vector<int> dfs(TreeNode* root, int distance, int& res) {
vector<int> dist;
if (!root) return dist;
if (!root->left && !root->right) {
dist.push_back(0);
return dist;
}
vector<int> left = dfs(root->left, distance, res);
vector<int> right = dfs(root->right, distance, res);
for (int i = 0; i < left.size(); ++i) {
for (int j = 0; j < right.size(); ++j) {
if (left[i] + right[j] + 2 <= distance) ++res;
}
}
for (int i = 0; i < left.size(); ++i) {
if (left[i] + 1 < distance) dist.push_back(left[i] + 1);
}
for (int i = 0; i < right.size(); ++i) {
if (right[i] + 1 < distance) dist.push_back(right[i] + 1);
}
return dist;
}
};