class Solution {
public:
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
};