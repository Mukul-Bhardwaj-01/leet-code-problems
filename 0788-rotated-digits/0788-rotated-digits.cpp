class Solution {
public:
    string s;
    int dp[6][2][2];
    int solve(int pos, bool tight, bool changed) {
        if(pos == s.size())
            return changed;
        if(dp[pos][tight][changed] != -1)
            return dp[pos][tight][changed];
        int limit = tight ? s[pos] - '0' : 9;
        int ans = 0;
        for(int d = 0; d <= limit; d++) {
            if(d == 3 || d == 4 || d == 7)
                continue;
            bool newTight = tight && (d == limit);
            bool newChanged =
                changed ||
                d == 2 || d == 5 || d == 6 || d == 9;
            ans += solve(pos + 1, newTight, newChanged);
        }
        return dp[pos][tight][changed] = ans;
    }
    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, true, false);
    }
};