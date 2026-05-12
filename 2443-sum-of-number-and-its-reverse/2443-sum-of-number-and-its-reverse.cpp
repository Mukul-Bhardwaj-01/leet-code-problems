class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; ++i) {
            int j = i, rev = 0;
            while(j) {
                rev = rev*10 + j%10;
                j /= 10;
            }
            if(i + rev == num) return true;
        }
        return false;
    }
};