class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;
        int ref = x;
        long num = 0;
        while(x) {
            num*=10;
            num += x % 10;
            x /= 10;
        }
        return num == ref;
    }
};