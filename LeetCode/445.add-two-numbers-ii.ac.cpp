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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<ListNode*>stk1, stk2;
    while(l1 != nullptr) {
      stk1.push(l1);
      l1 = l1->next;
    }
    while(l2 != nullptr) {
      stk2.push(l2);
      l2 = l2->next;
    }

    ListNode *ans = nullptr;
    ListNode *t = nullptr;
    int l = 0;
    while(!stk1.empty() || !stk2.empty()) {
      //cout << stk1.size() << " " << stk2.size() << "\n";
      if(!stk1.empty()) {
        l += stk1.top()->val;
        stk1.pop();
      }
      if(!stk2.empty()) {
        l += stk2.top()->val;
        stk2.pop();
      }
      ans = new ListNode(0);
      ans->val = l % 10;
      ans->next = t;
      l /= 10;
      t = ans;
    }
    while(l > 0) {
      ans = new ListNode(0);
      ans->val = l % 10;
      ans->next = t;
      l /= 10;
      t = ans;
    }
    return ans;
  }
};
