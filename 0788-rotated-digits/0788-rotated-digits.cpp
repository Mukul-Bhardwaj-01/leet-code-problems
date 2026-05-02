class Solution {
public:
    int flip(int num) {
        string r = "", s = to_string(num);
        for(int i = 0; i < s.length(); ++i) {
            char c = (s[i] == '0') ? '0' : (s[i] == '1' ? '1' : (s[i] == '2' ? '5' : (s[i] == '5' ? '2' : (s[i] == '6' ? '9' : (s[i] == '8' ? '8' : '6')))));
            r += c;
        }
        return stoi(r);
    }
    bool exists347(int num) {
        while(num > 0) {
            if(num%10 == 3 || num%10 == 4 || num%10 == 7) return true;
            num/=10;
        }
        return false;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i<=n; ++i)
            if(!exists347(i) && flip(i) != i) cnt++;
        return cnt;
    }
};