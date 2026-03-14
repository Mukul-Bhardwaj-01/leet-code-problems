class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if(k > total) return "";
        string ans = "";
        char prev = '#';
        for(int i = 0; i < n; i++) {
            for(char c = 'a'; c <= 'c'; c++) {
                if(c == prev) continue;
                int remaining = n - i - 1;
                int count = 1 << remaining;
                if(k > count) {
                    k -= count;
                } else {
                    ans += c;
                    prev = c;
                    break;
                }
            }
        }
        return ans;
    }
};