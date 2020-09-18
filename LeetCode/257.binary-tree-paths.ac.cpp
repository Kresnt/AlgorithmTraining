#pragma G++ optimize(2)
#pragma GCC optimize(2)

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
  vector<string> ans;
  int gao(TreeNode* u, vector<int>& vec) {
    vec.emplace_back(u->val);
    if (u->left == nullptr && u->right == nullptr) {
      string s;
      s += to_string(vec[0]);
      for (int i = 1; i < vec.size(); i++) {
        s += "->";
        s += to_string(vec[i]);
      }
      ans.emplace_back(s);
    } else {
      if (u->left) gao(u->left, vec);
      if (u->right) gao(u->right, vec);
    }
    vec.pop_back();
    return 0;
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    ans.clear();
    vector<int> st;
    if (root == nullptr) return ans;
    gao(root, st);
    return ans;
  }
};