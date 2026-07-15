class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) result++;
            }
        }
        for(auto &vec : grid) {
            result += *max_element(vec.begin(),vec.end());
        }
        for(int i = 0; i < n; ++i) {
            int maxVal = grid[0][i];
            for(int j = 1; j < n; ++j) {
                maxVal = max(maxVal, grid[j][i]);
            }
            result += maxVal;
        }
        return result;
    }
};