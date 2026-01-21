class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp_curSum = nums[0];

        int maxSum = dp_curSum;

        int n = nums.size();
        
        for (int i = 1; i < n; i++)
        {
            dp_curSum = max(nums[i], dp_curSum + nums[i]);

            maxSum = max(maxSum, dp_curSum);
        } 

        return maxSum;
    }
};