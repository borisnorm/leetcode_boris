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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
          return head;
        

        ListNode* newHead = reverseList(head->next);

        ListNode* nxt = head->next;
        nxt->next = head;
        // head 是 2, nxt 是 3
        //  1--> 2 <--3 <-- 4 <---5
        //         -->3

        // head 是 4, nxt 是 5
        // 4 -> 5 -> null
        // 完成上一步后 是
        // 4 -> 5
        //   <- 5
        // 所以需要下面的断链

        head->next = nullptr;
    
        return newHead;
    
    }
};
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode dummy(0);
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* pre = dummy_head;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while (cur->next)
        {
           nxt = cur->next;
           cur->next = nxt->next;
           nxt->next = pre->next;
           
           pre->next = nxt;
        }

        return dummy.next;
    }
};

*/

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
          return head;
        
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;
        while (cur)
        {
           nxt = cur->next;
           
           cur->next = pre;
           pre = cur;

           cur = nxt;
        }

        return pre;
    }
};
 */