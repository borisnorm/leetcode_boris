/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
          return head;
        Node* cur = head;
        unordered_map<Node*, Node*> orig2cpy;

        while(cur)
        {
            orig2cpy[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur)
        {
            orig2cpy[cur]->next = cur->next ? orig2cpy[cur->next] : nullptr;
            orig2cpy[cur]->random = cur->random ? orig2cpy[cur->random]: nullptr;

            cur = cur->next;
        }

        return orig2cpy[head];
    }
};