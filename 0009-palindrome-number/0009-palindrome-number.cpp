class Solution {
public:
    bool isPalindrome(long long x) {
        if(x<0) return 0;
        long long num=x;
        long long revnum=0;
        while(x>0) {
            revnum = revnum*10 + x%10;
            x/=10;
        }
        if(revnum==num) return 1;
        return 0;
    }
};