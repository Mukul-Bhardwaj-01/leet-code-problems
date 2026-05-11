class Solution {
public:
    int countEven(int num) {
        int temp = num, dSum = 0;
        while (temp > 0) {
            dSum += temp % 10;
            temp /= 10;
        }
        return (dSum % 2 == 0) ? (num / 2) : ((num - 1) / 2);
    }
};