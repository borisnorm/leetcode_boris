class Solution {
public:
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
};