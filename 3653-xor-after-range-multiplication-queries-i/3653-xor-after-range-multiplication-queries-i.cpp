class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        const long long mod = 1e9 + 7;

        vector<long long> mul(n, 1);

        // Large k → direct
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], val = q[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    mul[i] = (mul[i] * val) % mod;
                }
            }
        }

        // Small k → process per k
        for (int k = 1; k < B; k++) {
            for (auto &q : queries) {
                if (q[2] == k) {
                    int l = q[0], r = q[1], val = q[3];
                    for (int i = l; i <= r; i += k) {
                        mul[i] = (mul[i] * val) % mod;
                    }
                }
            }
        }

        int xorVal = 0;
        for (int i = 0; i < n; i++) {
            long long val = (nums[i] * mul[i]) % mod;
            xorVal ^= val;
        }

        return xorVal;
    }
};