class Solution {
    public int maxArea(int[] height) {

        if (height == null || height.length == 0)
          return 0;
        
        int n = height.length;

        int l = 0;
        int r = n - 1;

        int maxArea = 0;
        while (l < r)
        {
            int w = r - l;
            int h = Math.min(height[l], height[r]);
            int area = w * h;

            maxArea = Math.max(maxArea, area);

            if (height[l] < height[r])
              l++;
            else
              r--;
        }

        return maxArea;
    }
}