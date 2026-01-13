class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
    };

    int cap;
    Node* head;
    Node* tail;

    unordered_map<int, Node*> key2node;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        if (!key2node.count(key))
          return -1;

        Node* node = key2node[key];
        int val = node->val;
        updateLRUentry(node);
        return val;
    }
    
    void put(int key, int value) {
         if (!key2node.count(key) && key2node.size() == cap)
           removeLRUentry();
        
         if (key2node.count(key))
         {
            Node* node = key2node[key];
            node->val = value;
            updateLRUentry(node);
         }
         else
         {
            Node* node = new Node(key, value);
            key2node[key] = node;
            add2Head(node);
         }
    }

    void add2Head(Node* node)
    {
        Node* nxt = head->next;

        head->next = node;
        node->prev = head;

        node->next = nxt;
        nxt->prev = node;
    }
    void removeNode(Node* node)
    {
        Node* prev = node->prev;
        Node* nxt = node->next;

        prev->next = nxt;
        nxt->prev = prev;

    }
    void updateLRUentry(Node* node)
    {
        removeNode(node);
        add2Head(node);
    }

    void removeLRUentry()
    {
        Node* node = tail->prev;
        removeNode(node);
        key2node.erase(node->key);
        delete node;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */