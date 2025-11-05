class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        while(i<n && isspace(s[i])) i++;
        int sign = 1, num = 0;
        if(s[i]=='+') i++;
        else if(s[i]=='-') {
            sign = -1;
            i++;
        }
        while(i<n && isdigit(s[i])) {
            if(num > INT_MAX/10) return sign==-1?INT_MIN:INT_MAX;
            else if(num == INT_MAX/10) {
                if(sign>0 && (s[i]-'0')>=7) return INT_MAX;
                else if(sign<0 && (s[i]-'0')>=8) return INT_MIN;
            }
            num = num*10 + (s[i] - '0');
            i++;
        }
        return sign*num;
    }
};