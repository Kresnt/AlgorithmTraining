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
  ListNode* reverseKGroup(ListNode* head, int k) {
    vector<ListNode*>list(k, nullptr);
    ListNode* p = head;
    for(int i = 0;;) {
      if(p == nullptr)
        break;
      list[i] = p;
      p = p->next;
      if(i == k - 1)
        gao(list);
      i = (i + 1) % k;
    }
    return head;
  }

  void gao(vector<ListNode*> arr) {
    for(int i = 0, sz = arr.size(); i < sz / 2; ++i)
      swap(arr[i]->val, arr[sz - i - 1]->val);
  }
};
