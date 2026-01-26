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
          
          int n = lists.size();
          int interval = 1;
          while (interval < n)
          {
            for (int i = 0; i + interval < n; i += interval*2)
            {
                lists[i]= mergeTwoList(lists[i], lists[i+interval]);
            }

            interval *= 2;
          }

          return lists[0];
    }

    ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2)
          return nullptr;
        
        ListNode dummy;
        ListNode* cur = &dummy;

        while (l1 && l2)
        {
           if (l1->val < l2->val)
           {
              cur->next = l1;
              l1 = l1->next;
           }
           else
           {
              cur->next = l2;
              l2 = l2->next;
           }

           cur = cur->next;
        }

        cur->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
 /*
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
*/