class Solution {
public:
    int blackBox(vector<vector<int>>& matrix, int a) {
        int sum = 0;
        for(auto it : matrix) {
            sum += (int)(upper_bound(it.begin(),it.end(),a) - it.begin());
        }
        return sum;
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