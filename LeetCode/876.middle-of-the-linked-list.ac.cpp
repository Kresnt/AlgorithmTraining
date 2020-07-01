/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    int n = 0;
    ListNode *p = head;
    while(p != NULL) {
      n++;
      p = p->next;
    }
    int m = (n & 1) ? (n + 1) / 2 - 1 : n / 2;
    p = head;
    for(int i = 0; i < m; ++i)
      p = p->next;
    return p;
  }
};
