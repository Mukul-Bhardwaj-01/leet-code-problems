class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    int binarySearch(vector<vector<int>>& events, int i) {
        int l = i + 1, r = events.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (events[m][0] > events[i][1]) r = m;
            else l = m + 1;
        }
        return l;
    }
    int dfs(int i, int k, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (i >= events.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int next = binarySearch(events, i);
        int take = events[i][2] + dfs(next, k - 1, events, dp);
        int skip = dfs(i + 1, k, events, dp);
        return dp[i][k] = max(take, skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), cmp);
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return dfs(0, k, events, dp);
    }
};