class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
          return 0;

        int l = 0;
        int r = 0;
        int n = s.size();

        int char2freq[128] = {0};
        //unordered_map<char, int> char2freq;

        int ans = 0;
        while (r < n)
        {
           char c = s[r];
           char2freq[c]++;
           r++;

           while (char2freq[c] > 1)
           {
              char d = s[l];
              char2freq[d]--;
              l++;
           }

           ans = max(ans, r-l);
        }

        return ans;
    }
};