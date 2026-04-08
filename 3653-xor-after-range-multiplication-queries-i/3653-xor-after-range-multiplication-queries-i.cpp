class Solution {
public:
    static const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        vector<long long> mul(n, 1);
        // Step 1: Handle large k directly
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], val = q[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    mul[i] = (mul[i] * val) % MOD;
                }
            }
        }
        // Step 2: Handle small k using grouping + difference
        for (int k = 1; k < B; k++) {
            // For each remainder class
            vector<vector<long long>> diff(k);
            // Build compressed arrays
            for (int rem = 0; rem < k; rem++) {
                int sz = (n - rem + k - 1) / k;
                diff[rem].assign(sz + 1, 1);
            }
            // Apply queries
            for (auto &q : queries) {
                if (q[2] != k) continue;
                int l = q[0], r = q[1], val = q[3];
                int rem = l % k;
                int start = (l - rem) / k;
                int end = (r - rem) / k;
                diff[rem][start] = (diff[rem][start] * val) % MOD;
                if (end + 1 < diff[rem].size()) {
                    long long inv = modInverse(val);
                    diff[rem][end + 1] = (diff[rem][end + 1] * inv) % MOD;
                }
            }
            // Build prefix and apply to mul[]
            for (int rem = 0; rem < k; rem++) {
                long long curr = 1;
                for (int j = 0; j < diff[rem].size() - 1; j++) {
                    curr = (curr * diff[rem][j]) % MOD;
                    int idx = rem + j * k;
                    if (idx < n) {
                        mul[idx] = (mul[idx] * curr) % MOD;
                    }
                }
            }
        }
        // Step 3: Compute final XOR
        int xorVal = 0;
        for (int i = 0; i < n; i++) {
            long long val = (nums[i] * mul[i]) % MOD;
            xorVal ^= val;
        }
        return xorVal;
    }
    // Fast exponentiation for modular inverse
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