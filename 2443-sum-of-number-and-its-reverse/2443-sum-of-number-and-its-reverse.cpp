class Solution {
public:
    int rev(int n) {
        int ans = 0;
        while(n) {
            ans = ans*10 + n%10;
            n /= 10;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; ++i) {
            if(i + rev(i) == num) return true;
        }
        return false;
    }
};