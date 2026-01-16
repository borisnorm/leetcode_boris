class Solution {
public:
   
    // 1 <= prices.length <= 10^5
    // 0 < price[i] <= 10^4

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n < 2)
          return 0;
        
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < n; i++)
        {
           minPrice = min(prices[i], minPrice);

           if (prices[i] > minPrice)
             maxProfit = max(maxProfit, (prices[i] - minPrice));
        }

        return maxProfit;
    }
};