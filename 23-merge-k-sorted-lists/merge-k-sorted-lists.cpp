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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
          return nullptr;

        using T = ListNode*;
        auto cmp = [](const T& a, const T& b){
            return a->val > b->val;
        };

        priority_queue<T, vector<T>, decltype(cmp)> pq;
        
        for(ListNode* list: lists)
        {
          if (list)
            pq.push(list);
        }
        ListNode dummy(0);
        ListNode* dummy_head = &dummy;
        ListNode* cur = dummy_head;

        while(!pq.empty())
        {
            ListNode* node = pq.top();
            pq.pop();

            cur->next = node;
            cur = cur->next;

            if (node->next)
              pq.push(node->next);
        }

        cur->next = nullptr;

        return dummy.next;
    }
};