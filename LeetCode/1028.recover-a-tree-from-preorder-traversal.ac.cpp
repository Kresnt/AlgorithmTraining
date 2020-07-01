#pragma G++ optimize("O2")

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
  pair<int, int> parseString(string &s, int& idx) {
    int depth = 0;
    while(s[idx] == '-')
      depth++, idx++;
    int val = atoi(s.c_str() + idx);
    while(isdigit(s[idx]))
      idx++;
    //cout << ": " << val << " " << depth << endl;
    return make_pair(val, depth);
  }

  TreeNode* recoverFromPreorder(string S) {
    stack<pair<TreeNode*, int>>stk;
    pair<TreeNode*, int>u;
    TreeNode*root = nullptr;
    int idx = 0;
    while(idx < S.length()) {
      const pair<int, int> u = parseString(S, idx);
      if(stk.size() == 0) {
        root = new TreeNode(u.first);
        stk.push(make_pair(root, u.second));
      } else {
        while(stk.top().second >= u.second)
          stk.pop();

        TreeNode *node = new TreeNode(u.first);
        if(stk.top().first->left == nullptr) {
          stk.top().first->left = node;
          stk.push(make_pair(node, u.second));
        } else if(stk.top().first->right == nullptr) {
          stk.top().first->right = node;
          stk.push(make_pair(node, u.second));
        } else {
          cout << " ?? " << endl;
        }
      }
    }
    return root;
  }
};
