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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if(t == NULL)
      return true;
    if(s == NULL)
      return false;
    bool ans = false;
    if(s->val == t->val) {
      ans |= treeCompare(s, t);
    }
    if(!ans)
      ans |= isSubtree(s->left, t);
    if(!ans)
      ans |= isSubtree(s->right, t);
    return ans;
  }

  bool treeCompare(TreeNode *s, TreeNode *t) {
    if(s == NULL || t == NULL)
      return (t == s);
    if(s->val != t->val)
      return false;
    return treeCompare(s->left, t->left) && treeCompare(s->right, t->right);
  }
};
