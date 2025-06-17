class Solution {
public:
    int myAtoi(string s) {
        int result=0, i=0, sign=1;
        int n=s.length();
        while (i<n && isspace(s[i]))
            i++;
        if (i<n && (s[i]=='+' || s[i] =='-')) {
            sign = ((s[i]=='-')?-1:1);
            i++;
        }
        while(i<n && isdigit(s[i])) {
            if(result > INT_MAX/10 || (result == INT_MAX/10 && (s[i] - '0' > 7))) {
                return (sign==-1)?INT_MIN:INT_MAX;
            }
            result = result*10 + (s[i]-'0');
            i++;
        }
        return result*sign;
    }
};