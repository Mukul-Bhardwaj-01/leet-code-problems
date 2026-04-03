class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m, mod = 12345;
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<long long int> prefix(size,1), suffix(size,1);
        for(int i = 0; i<size-1; ++i) prefix[i + 1] = (prefix[i] * grid[i/m][i%m]) % mod;
        for(int i = size - 1; i>0; --i) suffix[i - 1] = (suffix[i] * grid[i/m][i%m]) % mod;
        for(int i = 0; i<size; ++i) ans[i/m][i%m] = (suffix[i] * prefix[i]) % mod;
        return ans;
    }
};