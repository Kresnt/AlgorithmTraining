/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    vector<int> ans;
    DFS(root, ans, 0);
    int n = ans.size();
    return ans[n - 1];
  }

  void DFS(TreeNode *root, vector<int>& ans, int dep) {
    if(root == nullptr)
      return;
    if(dep + 1 > ans.size())
      ans.push_back(0);
    ans[dep] += root->val;
    DFS(root->left, ans, dep + 1);
    DFS(root->right, ans, dep + 1);
  }
};
