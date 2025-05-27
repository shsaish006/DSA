// class Solution {
// public:
//     bool isPrime(long long num){
//         if(num<2) return false;
//         if(num==2) return true;
//         if(num%2==0) return false;
//         for(int i=3;i*1LL*i<=num;i+=2){
//             if(num%i==0) return false;
//         }
//         return true;
//     }
//     long long sumOfLargestPrimes(string s) {
//         unordered_set<long long>primes;
//         int n=s.size();
//         for(int i=0;i<n;++i){
//             for(int len=1;len<=7&&i+len<=n;++len){
//                 string sub=s.substr(i,len);
//                 if(sub[0]=='0'&&sub.length()>1) continue;
//                // int num=stoi(sub);
//                 long long num=stoll(sub);
//                 if(isPrime(num)){
//                     primes.insert(num);
//                 }
//             }
//         }
//         vector<int>primeList(primes.begin(),primes.end());
//         sort(primeList.rbegin(),primeList.rend());
//         long long sum=0;
//         for(int i=0;i<min(3,(int)primeList.size());++i){
//             sum+=primeList[i];
//         }
//         return sum;
        
//     }
// };
class Solution {
public:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (__int128)result * base % mod;
            base = (__int128)base * base % mod;
            exp /= 2;
        }
        return result;
    }
    
    bool isPrime(long long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;

        long long d = n - 1;
        int r = 0;
        while (d % 2 == 0) {
            d /= 2;
            r++;
        }

        
        vector<long long> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for (long long a : bases) {
            if (a >= n) break;
            long long x = modPow(a, d, n);
            if (x == 1 || x == n - 1) continue;
            bool passed = false;
            for (int i = 1; i < r; ++i) {
                x = (__int128)x * x % n;
                if (x == n - 1) {
                    passed = true;
                    break;
                }
            }
            if (!passed) return false;
        }
        return true;
    }
    
    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> uniquePrimes;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            string current = "";
            for (int j = i; j < n; ++j) {
                current += s[j];
                try {
                    long long num = stoll(current);
                    if (isPrime(num)) {
                        uniquePrimes.insert(num);
                    }
                } catch (const out_of_range& e) {
                    continue; 
                }
            }
        }

        vector<long long> primes(uniquePrimes.begin(), uniquePrimes.end());
        sort(primes.rbegin(), primes.rend());

        long long sum = 0;
        for (int i = 0; i < min(3, (int)primes.size()); ++i) {
            sum += primes[i];
        }

        return sum;
    }
};