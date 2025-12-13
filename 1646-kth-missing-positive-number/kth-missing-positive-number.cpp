class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int cnt = 0;
        int i = 0;
        int cur = 1;

        while (cnt < k)
        {
           while (i < n && arr[i] == cur)
           {
              i++;
              cur++;
           }
           cnt++;

           if (cnt != k)
             cur++;
        }

        return cur;

    }
};