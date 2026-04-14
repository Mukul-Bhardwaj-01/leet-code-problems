class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Expand factories based on capacity
        vector<int> fact;
        for (auto &f : factory) {
            int pos = f[0], cap = f[1];
            for (int i = 0; i < cap; i++) {
                fact.push_back(pos);
            }
        }

        int m = robot.size();
        int n = fact.size();

        // dp[i][j] = min cost to fix first i robots using first j factories
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 1e18));

        // Base case
        for (int j = 0; j <= n; j++) dp[0][j] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Skip this factory
                dp[i][j] = dp[i][j - 1];

                // Use this factory
                dp[i][j] = min(dp[i][j],
                               dp[i - 1][j - 1] + abs(robot[i - 1] - fact[j - 1]));
            }
        }

        return dp[m][n];
    }
};