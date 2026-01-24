/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // int k = 2;
      if (!head || !head->next)
        return head;

      ListNode dummy(0);
      ListNode* dummy_head = &dummy;
      dummy_head->next = head;

      ListNode* pre = dummy_head;
      ListNode* cur = head;
      ListNode* nxt = nullptr;

      for(int i = 1; i < 2; i++)
      {
         cur = cur->next;
      }
      
      ListNode* nxtHead = cur->next;
      cur->next = nullptr;
      
      cur = head;
      while(cur->next)
      {
         nxt = cur->next;
         cur->next = nxt->next;
         nxt->next = pre->next;

         pre->next = nxt;
      }

      cur->next = swapPairs(nxtHead);

      return dummy.next;
    }
};