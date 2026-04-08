class Solution {
public:
    static const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        vector<long long> mul(n, 1);
        unordered_map<int, long long> invCache;
        // Large k
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], val = q[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    mul[i] = (mul[i] * val) % MOD;
                }
            }
        }
        // Small k
        for (int k = 1; k < B; k++) {
            vector<vector<long long>> diff(k);
            for (int rem = 0; rem < k; rem++) {
                int sz = (n - rem + k - 1) / k;
                diff[rem].assign(sz + 1, 1);
            }
            for (auto &q : queries) {
                if (q[2] != k) continue;
                int l = q[0], r = q[1], val = q[3];
                int rem = l % k;
                int start = (l - rem) / k;
                int end = (r - rem) / k;
                if (rem + end * k > r) end--;
                diff[rem][start] = (diff[rem][start] * val) % MOD;
                if (end + 1 < diff[rem].size()) {
                    if (!invCache.count(val)) {
                        invCache[val] = modInverse(val);
                    }
                    long long inv = invCache[val];
                    diff[rem][end + 1] = (diff[rem][end + 1] * inv) % MOD;
                }
            }
            for (int rem = 0; rem < k; rem++) {
                long long curr = 1;
                for (int j = 0; j < diff[rem].size() - 1; j++) {
                    curr = (curr * diff[rem][j]) % MOD;
                    int idx = rem + j * k;
                    mul[idx] = (mul[idx] * curr) % MOD;
                }
            }
        }
        int xorVal = 0;
        for (int i = 0; i < n; i++) {
            long long val = (nums[i] * mul[i]) % MOD;
            xorVal ^= val;
        }
        return xorVal;
    }
    long long modExp(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    long long modInverse(long long x) {
        return modExp(x, MOD - 2);
    }
};