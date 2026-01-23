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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
          return head;
        
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while (cur && cur->next)
        {
           nxt = cur->next;
           if (cur->val == nxt->val)
           {
              // cur不同, 等待下一个相同值
              cur->next = nxt->next; 
           }
           else
           {
              cur = cur->next;
           }
        }

        return head;
    }
};