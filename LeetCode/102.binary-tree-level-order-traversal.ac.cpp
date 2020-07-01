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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    queue<pair<int, TreeNode*>>que;
    if(root != nullptr)
      que.push(make_pair(0, root));
    while(!que.empty()) {
      pair<int, TreeNode*> p = que.front();
      que.pop();
      if(ans.size() <= p.first) {
        ans.push_back(vector<int>(1, p.second->val));
      } else {
        ans[p.first].push_back(p.second->val);
      }
      if(p.second->left)
        que.push(make_pair(p.first + 1, p.second->left));
      if(p.second->right)
        que.push(make_pair(p.first + 1, p.second->right));
    }
    return ans;
  }
};
