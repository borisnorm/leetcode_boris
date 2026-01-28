class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int max_num = 0;
        for (int num: nums)
        {
          max_num = max(max_num, num);
          sum += num;
        }
        
        // as odd num
        if (sum & 0x1)
          return false;
         
        // even max_num == target
        // it would be fine as [max_num], [the remaining parts]
        int target = sum/2;
        if (max_num > target)
          return false;
        
        vector<int> dp(target+1, 0);
        // dp[j]: does exist the subset that its sum would be equal to i;
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            for (int sum = target; sum - num >=0; sum--)
            {
               //右侧 dp[sum] 表示 还有另外一组在上一轮 已经可以使得 和为 sum 了,  
               dp[sum] = dp[sum] | dp[sum-num];
            }

            if (dp[target])
              return true;
        }

        return dp[target] ? true : false;

    }
};