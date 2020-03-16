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
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    root = DFS(root, target);
    return root;
  }

  TreeNode* DFS(TreeNode *root, int target) {
    if(root == nullptr)
      return nullptr;
    root->left = DFS(root->left, target);
    root->right = DFS(root->right, target);
    if(root->left == nullptr && root -> right == nullptr && root->val == target) {
      return nullptr;
    }
    return root;
  }
};
