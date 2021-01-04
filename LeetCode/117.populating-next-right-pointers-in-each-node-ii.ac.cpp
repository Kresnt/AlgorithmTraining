/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    Node *node = nullptr, *nxt_lvl = nullptr, *last_node = nullptr;
    for (node = root; node != nullptr; node = nxt_lvl) {
      for (last_node = nullptr, nxt_lvl = nullptr; node != nullptr; node = node->next) {
        if (node->left != nullptr) {
          if (last_node == nullptr)
            last_node = nxt_lvl = node->left;
          else {
            last_node->next = node->left, last_node = last_node->next, last_node->next = nullptr;
          }
        }

        if (node->right != nullptr) {
          if (last_node == nullptr)
            last_node = nxt_lvl = node->right;
          else {
            last_node->next = node->right, last_node = last_node->next, last_node->next = nullptr;
          }
        }
      }
      node = nxt_lvl;
    }
    return root;
  }
};