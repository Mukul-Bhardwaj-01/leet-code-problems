class Solution {
public:
    int numSub(string s) {
        long long count = 0, length = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                length++;
            } else if (length != 0) {
                count = (count + length * (length + 1) / 2);
                length = 0;
            }
        }
        if (length != 0) {
            count = (count + length * (length + 1) / 2);
        }
        return count % 1000000007;
    }
};