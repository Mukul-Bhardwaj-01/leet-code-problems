class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string t = "0";
        long long sum = 0;
        for(char &c : s) {
            if(c != '0') {
                t += c;
                sum += c - '0';
            }
        }
        long long x = stoll(t);
        long long res = x * sum;
        return res;
    }
};