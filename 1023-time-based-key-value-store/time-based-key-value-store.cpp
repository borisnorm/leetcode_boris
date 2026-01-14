class TimeMap {
public:

    unordered_map<string, vector<pair<string, int>>> kv;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
          kv[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = kv.find(key);
         if (it == kv.end())
           return "";

        auto&  val_vec = it->second;

        int n = val_vec.size();
        int l = 0;
        int r = n;
        while (l < r)
        {
            int mid = l + (r - l)/2;

            if (val_vec[mid].second <= timestamp)
              l = mid + 1;
            else
              r = mid;
        }

        if (l - 1 < 0)
          return "";
        
        return val_vec[l-1].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */