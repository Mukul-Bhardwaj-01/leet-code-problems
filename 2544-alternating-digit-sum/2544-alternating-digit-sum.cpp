class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sign = 1;
        int sum = 0;
        for(char c : s) {
            sum = sum + sign*(c - '0');
            if(sign  == 1) sign = -1;
            else sign = 1;
        }
        return sum;
    }
};