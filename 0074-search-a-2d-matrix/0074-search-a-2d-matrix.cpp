class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                int l = 0, h = n - 1;
                while (l <= h) {
                    int mid2 = (l + h) / 2;
                    if (matrix[mid][mid2] == target) return true;
                    else if (matrix[mid][mid2] < target) l = mid2 + 1;
                    else h = mid2 - 1;
                }
                return false;
            }
            else if (target < matrix[mid][0]) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};