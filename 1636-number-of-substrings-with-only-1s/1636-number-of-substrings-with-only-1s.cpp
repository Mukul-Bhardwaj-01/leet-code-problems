class Solution {
public:
    int numSub(string s) {
        long long count = 0, length = 0;
        const long mod = 1000000007;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                length++;
            } else if (length != 0) {
                count = (count + length * (length + 1) / 2) % mod;
                length = 0;
            }
        }

        if (length != 0) {
            count = (count + length * (length + 1) / 2) % mod;
        }

        return count % mod;
    }
};