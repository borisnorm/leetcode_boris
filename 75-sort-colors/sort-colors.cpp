class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // [0, low)  全是 0
        // [low, mid)  全是 1
        // [mid, high] 未处理区域
        // (high, end] 全是 2
        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
               // low的位置 写入 mid 的0 
               // 1. low = mid;
               // 2. low < mid
               swap(nums[low], nums[mid]);
               low++;
               mid++;
               // 保证[0, low) 全是 0
               // 保证[low, mid) 全是 1,
            }
            else if (nums[mid] == 1)
            {
               //保证 [low, mid) 全是 1
               mid++;
            }
            else  // 默认 num[mid] == 2
            {
               swap(nums[mid], nums[high]);
               high--;
            }
        }
    }
};