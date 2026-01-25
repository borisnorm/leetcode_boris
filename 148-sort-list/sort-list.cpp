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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;

        slow->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        head = mergeSortList(left, right);
        
        return head;
    }

    ListNode* mergeSortList(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2)
          return nullptr;
        
        ListNode dummy;
        ListNode* dummy_head = &dummy;

        ListNode* cur = dummy_head;
        
        while (l1 && l2)
        {
           if (l1->val < l2->val)
           {
              cur->next = l1;
              l1 = l1->next;
              cur = cur->next;
           }
           else
           {
              cur->next = l2;
              l2 = l2->next;
              cur = cur->next;
           }
        }
        
        // l2 could be nullptr;
        cur->next = l1 ? l1 : l2;

        return dummy.next;
    }
};