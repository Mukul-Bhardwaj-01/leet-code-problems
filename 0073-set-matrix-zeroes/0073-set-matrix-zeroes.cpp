class Solution {
public:
    void markrows(set<int> row_zero, vector<vector<int>>& matrix, int rows, int cols) {
        for(auto it: row_zero) {
            for(int i=0; i<cols; i++) {
                matrix[it][i] = 0;
            }
        }
    }
    void markcols(set<int> col_zero, vector<vector<int>>& matrix, int rows, int cols) {
        for(auto it: col_zero) {
            for(int i=0; i<rows; ++i)
                matrix[i][it] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> row_zero, col_zero;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(matrix[i][j]==0) {
                    row_zero.insert(i);
                    col_zero.insert(j);
                }
            }
        }
        markrows(row_zero, matrix, m, n);
        markcols(col_zero, matrix, m, n);
    }
};