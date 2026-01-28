class Solution {
public:
    int numTrees(int n) {
        if (n < 0)
          return 0;
        
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
        {
           long long total = 0;
           for(int root = 1; root <= i; root++)
           {
              int left = root-1;
              int right = i - root;
              total += dp[left] * dp[right];
           }
           dp[i] = total;
        }

        return static_cast<int>(dp[n]);
    }
};