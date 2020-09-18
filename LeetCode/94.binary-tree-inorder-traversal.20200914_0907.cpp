/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*, int> P;
class Solution {
 public:
  vector<int> ans;
  stack<P> s;
  vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* node = root;
    if(root != nullptr) s.push({root, 0});
    else return ans;
    while (!s.empty()) {
      P u = s.top();
      s.pop();
      node = u.first;
      if (u.second == 0) {
        s.push({node, 1});
        if (node->left != nullptr) s.push({node->left, 0});
      } else {
        ans.emplace_back(node->val);
        if (node->right != nullptr) s.push({node->right, 0});
      }
    }
    return ans;
  }
};