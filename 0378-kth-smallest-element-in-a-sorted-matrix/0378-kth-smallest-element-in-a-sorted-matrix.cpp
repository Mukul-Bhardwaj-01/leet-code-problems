class Solution {
public:
    int blackBox(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int row = n - 1, col = 0;
        int count = 0;
        while(row >= 0 && col < n) {
            if(matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            }
            else row--;
        }
    return count;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low<=high) {
            int mid = low + (high - low)/2;
            int x = blackBox(matrix, mid);
            if(x <= k-1) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};