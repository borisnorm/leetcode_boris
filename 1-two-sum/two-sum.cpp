class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<pair<int, int>> num_vec;
        for (int i = 0; i < n; i++)
        {
           num_vec.push_back({nums[i], i});
        }

        sort(num_vec.begin(), num_vec.end());

        int l = 0;
        int r = n - 1;

        vector<int> res;
        while (l < r)
        {
            long long sum = num_vec[l].first + num_vec[r].first;
            if (sum < target)
              l++;
            else if (sum > target)
              r--;
            else
            {
               int l_idx = num_vec[l].second;
               int r_idx = num_vec[r].second;
               if (l_idx > r_idx)
                 swap(l_idx, r_idx);
                
                res.push_back(l_idx);
                res.push_back(r_idx);
                return res;
            }
        }

        return res;
    }
/*
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> num2idx;
        int n = nums.size();
        
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
           int remain = target - nums[i];
           if (num2idx.count(remain))
           {
              int pre_idx = num2idx[remain];
               res.push_back(pre_idx);
               res.push_back(i);
               return res;
           }

           num2idx[nums[i]] = i;
        }

        return res;
    }
    */
};