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
    ListNode* partition(ListNode* head, int x) { 
        if (!head || !head->next)
          return head;
        
        ListNode dummyLess(0);
        ListNode* dummyless_head = &dummyLess;
        ListNode* cur_less = dummyless_head;

        ListNode dummyGreater(0);
        ListNode* dummygreater_head = &dummyGreater;
        ListNode* cur_greater = dummygreater_head;

        ListNode* cur = head;

        while(cur)
        {
            if (cur->val < x)
            {
               cur_less->next = cur;
               cur_less = cur_less->next;
            }
            else
            {
               cur_greater->next = cur;
               cur_greater = cur_greater->next;
            }

            cur = cur->next;
        }

        cur_less->next = dummyGreater.next;
        cur_greater->next = nullptr;

        
        return dummyLess.next;
    }
};