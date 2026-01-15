class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty())
          return 0;

        int n = height.size();

        int l = 0;
        int r = n - 1;
        int maxArea = 0;
        while (l < r)
        {
           int width = r - l;
           int h = min(height[r], height[l]);
           int area = width * h;
           
           maxArea = max(maxArea, area);

           // for next higher height for shorter side;
           // higher height can get large area, even with less width.
           if (height[l] < height[r])
             l++;
           else
             r--;
        }

        return maxArea;
    }
};