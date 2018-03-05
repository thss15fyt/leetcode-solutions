class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> isPrime(n, true);
        double sqrt_n = sqrt((double)n);
        for(int num = 2; num < n; ++num) {
            if(isPrime[num]) {
                count++;
                if(num < sqrt_n)
                    for(int i = num; i * num < n; ++i)
                        isPrime[i * num] = false;
             }
        }
        return count;
    }
};