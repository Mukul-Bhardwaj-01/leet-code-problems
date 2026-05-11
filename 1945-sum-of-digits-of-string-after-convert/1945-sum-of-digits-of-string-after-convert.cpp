class Solution {
public:
    void sumDigits(int &n) {
        int num = n;
        int sum = 0;
        while(num > 0) {
            sum += (num%10);
            num /= 10;
        }
        n = sum;
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
            sumDigits(resNum);
            if(resNum < 10) break;
        }
        return resNum;
    }
};