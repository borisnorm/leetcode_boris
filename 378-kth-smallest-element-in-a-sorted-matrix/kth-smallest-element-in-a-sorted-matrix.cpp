class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int l = matrix[0][0];
        int r = matrix[n-1][n-1];

        while (l < r)
        {
           long long mid = l + (r - l)/2;

           // first >= k
           if (countLessThan(matrix, mid) < k)
             l = mid + 1;
           else
             r= mid;
        }

        return l;
    }

    int countLessThan(vector<vector<int>>& matrix, int mid)
    {

       int n = matrix.size();

       int r = 0;
       int c = n -1;

       int cnt = 0;

       while (r < n && c >=0)
       {
          if (matrix[r][c] <= mid)
          {
              cnt += c + 1;
              r++;
          }
          else
          {
             c--;
          }
       }

       return cnt;
    }
};