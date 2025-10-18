class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        for(long long i = 0; i<=x; ++i) {
            if(i*i <= x) ans = i;
            else break;
        }
        return (int)ans;
    }
};