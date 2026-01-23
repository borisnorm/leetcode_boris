class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (long long i = 2; i * i < n; i++)
        {
            //if (!isPrime[i])
              //continue; 

            for (long long j = i * i; j < n; j+= i)
            {
                isPrime[(int)j] = false;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n ; i++)
          if (isPrime[i])
            cnt++;
        
        return cnt;
        
    }
};