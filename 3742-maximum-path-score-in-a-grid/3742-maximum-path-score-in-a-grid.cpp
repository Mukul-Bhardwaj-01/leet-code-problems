class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j, int k, vector<vector<int>>& grid) {
        if(i >= m || j >= n || k < 0)
            return -1e9;
        int cost = (grid[i][j] > 0);
        if(k - cost < 0)
            return -1e9;
        if(i == m - 1 && j == n - 1)
            return grid[i][j];
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        int nk = k - cost;
        int right = dfs(i, j + 1, nk, grid);
        int down  = dfs(i + 1, j, nk, grid);
        return dp[i][j][k] =
            grid[i][j] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,
            vector<vector<int>>(n,
                vector<int>(k + 1, -1)));
        int ans = dfs(0, 0, k, grid);
        return ans < 0 ? -1 : ans;
    }
};