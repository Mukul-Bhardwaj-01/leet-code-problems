class Solution {
public:
    int rev(int a) {
        int r = 0;
        while(a > 0) {
            r = r*10 + a%10;
            a /= 10;
        }
        return r;
    }
    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};