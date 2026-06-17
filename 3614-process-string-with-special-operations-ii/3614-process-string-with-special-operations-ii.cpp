class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(char &c : s) {
            if(c >= 'a' && c <= 'z') len++;
            else if(c == '*' && len) len--;
            else if(c == '#') len*=2;
        }
        if(k >= len) return '.';

        int n = s.length();
        for(int i = n-1; i>=0; --i) {
            if(s[i] == '#') {
                len /= 2;
                if(k >= len) {
                    k = k%len;
                }
            }
            else if(s[i] == '%') k = len - 1 - k;
            else if(s[i] >= 'a' && s[i] <= 'z') {
                if(len - 1 == k) return s[i];
                len--;
            }
            else if(s[i] == '*') len++;
        }
        return '.';
    }
};