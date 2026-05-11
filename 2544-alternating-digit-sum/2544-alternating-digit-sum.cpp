class Solution {
public:
    int alternateDigitSum(int n) {
        int digits = (int)log10(n) + 1;
        int sign;
        if(digits % 2) sign = 1;
        else sign = -1;
        int sum = 0;
        while(n > 0) {
            int num = n % 10;
            num *= sign;
            n /= 10;
            sign *= -1;
            sum += num;
        }
        return sum;
    }
};