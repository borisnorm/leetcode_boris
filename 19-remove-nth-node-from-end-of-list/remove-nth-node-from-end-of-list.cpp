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
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            if (!head)
              return head;
            
            ListNode dummy;
            ListNode* dummy_head = &dummy;
            dummy_head->next = head;

            ListNode* slow = dummy_head;
            ListNode* fast = dummy_head;

            for (int i = 0; i < n + 1 && fast; i++)
              fast = fast->next;

            while(fast)
            {
               slow = slow->next;
               fast = fast->next;
            }

            ListNode* del = slow->next;
            slow->next = del->next;
            delete del;

            return dummy.next;    
    }
};
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          if (!head)
            return head;
           
           ListNode dummy(0);
           ListNode* dummy_head = &dummy;
           dummy_head->next = head;

           ListNode* cur = head;
           int cnt = 1;
           while (cur->next)
           {
              cnt++;
              cur = cur->next;
           }

           // reach the previous node of the target node
           cur = dummy_head;  //从 第0点开始
           for (int i = 0; i < cnt - n; i++)
           {
             cur = cur->next;
           }

           ListNode* pre = cur;
           cur = cur->next;
           ListNode* nxt = cur->next;

           pre->next = nxt;

           return dummy.next;
    }
};
*/