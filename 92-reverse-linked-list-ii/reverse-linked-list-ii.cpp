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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next)
          return head;
        
        ListNode dummy;
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* pre = dummy_head;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        for (int i = 1; i < left && cur; i++)
        {
           pre = cur;
           cur = cur->next;
        } 

        for (int i = left; i < right && cur->next; i++)
        {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;

            pre->next = nxt;
        }

        return dummy.next;
        
    }
};