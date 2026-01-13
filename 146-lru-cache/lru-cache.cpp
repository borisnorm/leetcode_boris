class LRUCache {
public:
    int cap;

    // key , kv_it
    unordered_map<int, list<pair<int, int>>::iterator> key2it;
    // key, val
    list<pair<int, int>> kvl;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!key2it.count(key))
          return -1;
        
        int val = key2it[key]->second;

        updateLRUentry(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (!key2it.count(key) && kvl.size() == cap)
          removeLRUentry();
        
        updateLRUentry(key, value);
    }

    void updateLRUentry(int key, int val)
    {
        //delete if exising from kvl
        if (key2it.count(key))
          kvl.erase(key2it[key]);

        //add it to kvl front
        kvl.push_front({key, val});

        //update key2it with new it;
        key2it[key] = kvl.begin();
    }
    
    void removeLRUentry()
    {
       //get last key first
       auto it = prev(kvl.end());

       //delete the key2it entry
       int key = it->first;
       key2it.erase(key);

       kvl.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */