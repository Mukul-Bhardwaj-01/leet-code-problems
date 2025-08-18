class Solution {
public:
    int func(int i) {
        if(i<=1) return i;
        return func(i-1) + func(i-2);
    }
    int fib(int n) {
        return func(n);
    }
};