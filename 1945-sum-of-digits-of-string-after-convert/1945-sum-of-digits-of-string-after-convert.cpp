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
        return;
    }
    int getLucky(string s, int k) {
        string res = "";
        for(char c : s) {
            res += to_string(c - 'a' + 1);
        }
        int resNum = 0;
        for(char c : res) {
            resNum += (c - '0');
        }
        for(int i = 1; i<k; ++i) {
            sumDigits(resNum);
            if(resNum < 10) break;
        }
        return resNum;
    }
};