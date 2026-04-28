class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m*n;
        vector<int> grid1D(size, 0);
        for(int i = 0; i<m; ++i) {
            for(int j = 0; j<n; ++j)
                grid1D[i*n + j] = grid[i][j];
        }
        sort(grid1D.begin(),grid1D.end());
        int median = grid1D[size/2];
        int res = 0;
        for(int &i : grid1D) {
            if(abs(i - median) % x != 0) return -1;
            res += (abs(i - median)/x);
        }
        return res;
    }
};