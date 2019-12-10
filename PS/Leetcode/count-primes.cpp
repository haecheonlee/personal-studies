class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        bool primes[n];
        
        for(int i=0; i<n; i++) {
            primes[i] = true;
        }
        
        for(long long int i=2; i<n; i++) {
            if(!primes[i]) continue;
            
            for(long long int j=i*i; j<n; j+=i) {
                primes[j] = false;
            }
        }
        
        int count = 0;
        for(int i=2; i<n; i++) {
            if(primes[i]) count++;
        }
        
        return count;
    }
};
/*
https://leetcode.com/problems/count-primes/
*/
