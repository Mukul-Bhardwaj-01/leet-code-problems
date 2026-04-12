class Solution {
public:
    int dist(int a, int b) {
        return abs(a/6 - b/6) + abs(a%6 - b%6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        // dp[i][l][r] = min cost to type from i-th index,
        // when left finger at l and right finger at r
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));
        
        function<int(int,int,int)> solve = [&](int i, int l, int r) {
            if(i == n) return 0;
            
            int curr = word[i] - 'A';
            
            if(dp[i][l][r] != -1) return dp[i][l][r];
            
            // use left finger
            int costLeft = (l == 26 ? 0 : dist(l, curr)) + solve(i+1, curr, r);
            
            // use right finger
            int costRight = (r == 26 ? 0 : dist(r, curr)) + solve(i+1, l, curr);
            
            return dp[i][l][r] = min(costLeft, costRight);
        };
        
        return solve(0, 26, 26); // both fingers initially unused
    }
};