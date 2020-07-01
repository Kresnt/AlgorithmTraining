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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0)
      return NULL;
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > >h;
    ListNode *head = NULL;
    ListNode *p = NULL;
    ListNode *q = NULL;

    for(ListNode* i : lists) {
      if(i != NULL) {
        h.push(make_pair(i->val, i));
      }
    }
    while(!h.empty()) {
      pair<int, ListNode*> t = h.top();
      h.pop();
      int val = t.first;
      if(t.second->next != NULL) {
        h.push(make_pair(t.second->next->val, t.second->next));
      }

      q = new ListNode(val);
      if(p == NULL) {
        head = p = q;
      } else {
        p->next = q;
        p = q;
      }
    }
    return head;

  }
};
