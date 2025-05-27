class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
      
        if (n <= k && m <= k) {
            return 0;
        }

       
        
        if (n > k && m <= k) {
            
            return (long long)k * (n - k);
        }

        
        if (m > k && n <= k) {
          
            return (long long)k * (m - k);
        }

        
        return 0; 
    }
};