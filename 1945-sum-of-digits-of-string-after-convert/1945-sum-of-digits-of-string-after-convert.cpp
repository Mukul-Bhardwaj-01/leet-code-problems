class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while(n > 0) {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int resNum = 0;
        for(char c : s) {
            string temp =  to_string(c - 'a' + 1);
            for(char digit : temp) {
                resNum += (digit - '0');
            }
        }
        for(int i = 1; i<k; ++i) {
            resNum = sumDigits(resNum);
            if(resNum < 10) break;
        }
        return resNum;
    }
};