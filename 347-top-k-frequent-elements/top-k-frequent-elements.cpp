class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          // count freq
         unordered_map<int, int> num2freq;
         for (int num: nums)
           num2freq[num]++;
 
         int n = nums.size();
         vector<vector<int>> bucket(n+1);
         // insert freq into buckets
         for (auto it: num2freq)
           bucket[it.second].push_back(it.first);
        
         // traverse the buckets in reverse order to fill the result
         int cnt = 0; 
         vector<int> res;
         for (int i = n; i >= 1 && cnt < k; i--)
         {
            auto val_vec = bucket[i];
            for (int num: val_vec)
            {
                res.push_back(num);
                cnt++;
                if (cnt == k)
                  break;
            }
         }

         return res;
    }
   /*
    vector<int> topKFrequent(vector<int>& nums, int k) {
         int n = nums.size();

         unordered_map<int, int> num2freq;
         for (int num: nums)
           num2freq[num]++;
        
         //using T = pair<int, int>;
         //auto cmp = [](const T&a, const T&b){
         //   return a.second > b.second;
         ///};
         //priority_queue<T, vector<T>, decltype(cmp)> pq;
         priority_queue<pair<int, int>> pq;

         for (auto it : num2freq)
            pq.push({it.second, it.first});

         int cnt = 0;
         vector<int> res;
         for (int i = 0; i < k; i++)
         {
            auto it = pq.top();
            pq.pop();
            res.push_back(it.second);
         }
         return res;
    }

    */
};