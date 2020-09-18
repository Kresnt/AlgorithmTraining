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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    if(n == 0)
      return nullptr;
    TreeNode *root  = DFS(nums, 0, n - 1);
    return root;
  }
 private:
  TreeNode * DFS(vector<int>&nums, int l, int r)const {
    int m = (l + r) >> 1;
    TreeNode * root = new TreeNode(nums[m]);
    if(l == r) return root;
    if(l < m) root->left = DFS(nums, l, m - 1);
    if(m < r) root->right = DFS(nums, m + 1, r);
    return root;
  }
};
