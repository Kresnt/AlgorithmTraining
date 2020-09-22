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
  struct S {
    // [State 0] Strict subtree: All the nodes below this node are covered, but not this node.
    // [State 1] Normal subtree: All the nodes below and including this node are covered, but there is no camera here.
    // [State 2] Placed camera: All the nodes below and including this node are covered, and there is a camera here
    // (which may cover nodes above this node).
    int a, b, c;
  };
  const int inf = 0x3f3f3f3f;

 public:
  S gao(TreeNode* root) {
    S s = {0, 0, inf};
    if (root == nullptr) return s;
    S l = gao(root->left), r = gao(root->right);
    s.a = l.b + r.b;
    s.b = min(l.c + min(r.b, r.c), r.c + min(l.b, l.c));
    s.c = 1 + min(l.a, min(l.b, l.c)) + min(r.a, min(r.b, r.c));
    return s;
  }
  int minCameraCover(TreeNode* root) {
    S s = gao(root);
    return min(s.b, s.c);
  }
};


/**********************************************/
/* greedy
 */
class Solution {
  int ans;
  set<TreeNode*> covered;

 public:
  int minCameraCover(TreeNode* root) {
    ans = 0;
    covered.clear();
    covered.insert(nullptr);
    gao(root, nullptr);
    return ans;
  }

  void gao(TreeNode* node, TreeNode* par) {
    if (node == nullptr) return;
    gao(node->left, node);
    gao(node->right, node);
    if ((par == nullptr && covered.find(node) == covered.end()) || covered.find(node->left) == covered.end() ||
        covered.find(node->right) == covered.end()) {
      ans++;
      covered.insert(node);
      covered.insert(par);
      covered.insert(node->left);
      covered.insert(node->right);
    }
  }
};