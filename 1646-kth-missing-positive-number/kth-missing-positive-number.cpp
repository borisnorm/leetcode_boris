class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();

        auto missing = [&](int i){
            return arr[i]-(i+1);
        };

        if (missing(n-1) < k)
          return arr[n-1] + (k - missing(n-1));
        
        int l = 0;
        int r = n -1;
  
        //find first mid >= k
        // mid 是手段, 找的是 l
        while(l < r)
        {
           int mid = l + (r-r)/2;
           if (missing(mid) < k)
             l = mid + 1;
            else
              r = mid;
        }

        return l + k;
    }
};