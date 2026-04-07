class Solution {
public:
    int fib(int n) {
        if(n <= 1)
        return n;

        // calculate fib for n-1 and n-2
        int ans = fib(n-1) + fib(n-2);

        return ans;
    }
};