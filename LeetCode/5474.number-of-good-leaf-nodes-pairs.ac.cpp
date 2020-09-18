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

  vector<int> gao(const TreeNode* root, const int distance, int &ans) {
    if(root == nullptr)
      return {};
    if(root->left == nullptr && root->right == nullptr) {
      return {1};
    }
    vector<int>lch = gao(root->left, distance, ans);
    vector<int>rch = gao(root->right, distance, ans);
    for(int i = 0; i < min(distance, (int)lch.size()); i++) {
      if(lch[i])
        for(int j = 0; j < min(distance, (int)rch.size()); j++) {
          if(i + j + 2 <= distance)
            ans += lch[i] * rch[j];
        }
    }
    vector<int>v(max(lch.size(), rch.size()) + 1);
    for(int i = 0; i < lch.size(); i++)
      v[i + 1] += lch[i];
    for(int i = 0; i < rch.size(); i++)
      v[i + 1] += rch[i];
    return v;
  }

  int countPairs(TreeNode* root, int distance) {
    int ans(0);
    gao(root, distance, ans);
    return ans;
  }
};
