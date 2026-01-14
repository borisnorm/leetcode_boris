class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        int maxLen = 0;
        int i = 0;

        while (i < n)
        {
           int start = i;
           while (i + 1 < n && arr[i] < arr[i+1])
             i++;
           int peak = i;

           while (i + 1 < n && arr[i] > arr[i+1])
             i++;
           int end = i;

           if (start < peak && peak < end)
           {
              maxLen = max(maxLen, end - start + 1);
           } 

           if (start == end)
             i++;
        }

        return maxLen;
    }
};