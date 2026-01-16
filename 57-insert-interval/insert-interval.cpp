class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         
           vector<vector<int>> res;
           int n = intervals.size();
 
           // n== 1 不是问题, newInterval 可以插进来
           int i = 0;
           int new_start = newInterval[0];
           int new_end   = newInterval[1];

           // [ old ]  [ new ]
           while (i < n && intervals[i][1] < new_start)
           {
              res.push_back(intervals[i]);
              i++;
           }

           //    [ new ]
           // [ old ]
           // continues to merge
           while (i < n && intervals[i][0] <= new_end)
           {
               new_start = min(new_start, intervals[i][0]);
               new_end   = max(new_end,   intervals[i][1]);
               i++;
           }
           res.push_back({new_start, new_end});

           //  [new] [old]
           while (i < n &&  new_end < intervals[i][0])
           //while (i < n)
           {
              res.push_back(intervals[i]);
              i++;
           }

           return res;
    }
};