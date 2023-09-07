class Solution {
public:
    // Recursive function to calculate x^n
    double solve(double x, long n) {
        // Base case: if n is 0, return 1 (x^0 = 1)
        if(n == 0)
            return 1;
        
        // Handle negative exponents by taking the reciprocal
        if(n < 0)
            return 1/solve(x, -n);
        
        // If n is even, recursively calculate x^(n/2)
        if(n % 2 == 0) {
            return solve(x * x, n / 2);
        }
        
        // If n is odd, recursively calculate x^((n-1)/2) and multiply by x
        return x * solve(x * x, (n - 1) / 2);
    }
    
    // Public function to calculate x^n with integer n
    double myPow(double x, int n) {
        // Convert n to a long to handle the case of INT_MIN.  becoz |intmin|>|intmax| bcoz of 0
        return solve(x, (long)n);
    }
};
