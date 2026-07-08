class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        // pos = original indices of all non-zero digits
        vector<int> pos;

        // digit value of every non-zero digit
        vector<int> digit;

        // Build compressed array of non-zero digits
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // pow10[i] = 10^i % MOD
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefNum[i]
        // concatenated value of first i non-zero digits
        // prefNum[0] = 0
        vector<long long> prefNum(m + 1, 0);

        // prefSum[i]
        // sum of first i non-zero digits
        vector<long long> prefSum(m + 1, 0);

        for (int i = 1; i <= m; i++) {
            prefNum[i] = (prefNum[i - 1] * 10 + digit[i - 1]) % MOD;
            prefSum[i] = prefSum[i - 1] + digit[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // first non-zero digit >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // first non-zero digit > r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            // no non-zero digit in this interval
            if (L == R) {
                ans.push_back(0);
                continue;
            }

            // number of non-zero digits
            int len = R - L;

            // digit sum
            long long sum = prefSum[R] - prefSum[L];

            /*
                Remove the prefix mathematically.

                prefNum[R]
                =
                prefNum[L] * 10^(len)
                + desired_number

                Therefore,

                desired_number =
                prefNum[R] - prefNum[L] * 10^(len)
            */

            long long x =
                (prefNum[R]
                - (prefNum[L] * pow10[len]) % MOD
                + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};