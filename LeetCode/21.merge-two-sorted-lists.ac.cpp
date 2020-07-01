#pragma G++ optimize("O2")
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : vala(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* root = nullptr;
    ListNode* cur = nullptr;
    ListNode* p = nullptr;
    while(l1 != nullptr || l2 != nullptr) {
      if(l2 != nullptr && l1 != nullptr) {
        if(l1->val < l2->val)
          cur = l1, l1 = l1->next;
        else
          cur = l2, l2 = l2->next;
      } else if(l1 != nullptr)
        cur = l1, l1 = l1->next;
      else
        cur = l2, l2 = l2->next;

      if(root == nullptr)
        root = p = cur;
      else
        p->next = cur, p = p->next;
    }
    return root;
  }
};
