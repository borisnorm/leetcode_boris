class Solution {
public:
    int titleToNumber(string columnTitle) {
       if (columnTitle.empty())
         return 0;

       long long sum = 0;
       int n = columnTitle.size();
       for (int i = 0; i < n; i++)
          sum = sum * 26 + (columnTitle[i] - 'A' + 1);
    
       return static_cast<int>(sum);

    }
};