class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        if (nums.empty())
          return {};

        vector<int> res(n, 1);

         // res[i] = product left than i;
        for (int i = 1; i < n; i++)
          res[i] = res[i-1] * nums[i-1];

        int tmp = 1;
        for (int i = n - 1 ; i >= 0; i--)
        {
            res[i] = res[i] * tmp;
            tmp = tmp * nums[i];
        }

        return res;
    }
};