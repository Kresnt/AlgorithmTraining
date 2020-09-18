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
  int gao(TreeNode* root, bool& ans) {
    if (root == nullptr || !ans) return 0;
    int l = gao(root->left, ans), r = gao(root->right, ans);
    ans &= abs(l - r) <= 1;
    return max(l, r) + 1;
  }

  bool isBalanced(TreeNode* root) {
    bool ans(true);
    gao(root, ans);
    return ans;
  }
};
