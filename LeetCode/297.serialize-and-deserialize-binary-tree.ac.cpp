/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(root == nullptr) {
      return "(X)";
    }
    return "(" + serialize(root->left) + to_string(root->val) + serialize(root->right) + ")";
  }

  TreeNode* parse(const string data, int& ptr) {
    ptr++;
    if(data[ptr] == 'X') {
      ptr += 2;
      return nullptr;
    }
    auto cur = new TreeNode(0);
    cur->left = parse(data, ptr);
    cur->val = atoi(data.c_str() + ptr);
    while(isdigit(data[ptr]) || data[ptr] == '+' || data[ptr] == '-')
      ptr++;
    cur->right = parse(data, ptr);
    ptr++;
    return cur;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int ptr(0);
    return parse(data, ptr);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

