class Solution {
public:
    void leftShift(vector<int>& arr, int m, int k) {
        while (k > 0) {
            int temp = arr[0];
            for(int i = 0; i<m-1; ++i) {
                arr[i] = arr[i+1];
            }
            arr[m-1] = temp;
            k--;
        }
    }
    void rightShift(vector<int>& arr, int m, int k) {
        while(k > 0) {
            int temp = arr[m-1];
            for(int i = m-1; i>0; --i) {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
            k--;
        }
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k = k % n;
        vector<vector<int>> matCopy = mat;
        for(int i = 0; i<m; ++i) {
            if(i%2 == 0) leftShift(matCopy[i], n, k);
            else rightShift(matCopy[i], n, k);
        }
        for(int i = 0; i<m; ++i) {
            for(int j = 0; j<n; ++j) {
                if(matCopy[i][j] != mat[i][j]) return false;
            }
        }
        return true;
    }
};