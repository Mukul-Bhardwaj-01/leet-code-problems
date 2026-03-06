class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<bool> rowOnes(m), colOnes(n);
        for(int i = 0; i<m; ++i) {
            int sum = mat[i][0];
            for(int j = 1; j<n; ++j) {
                sum+=mat[i][j];
                if(sum>1) break;
            }
            rowOnes[i] = (sum==1);
        }
        for(int j = 0; j<n; ++j) {
            int sum = mat[0][j];
            for(int i = 1; i<m; ++i) {
                sum+=mat[i][j];
                if(sum>1) break;
            }
            colOnes[j] = (sum == 1);
        }
        int count = 0;
        for(int i = 0; i<m; ++i) {
            if(!rowOnes[i]) continue;
            for(int j = 0; j<n; ++j) {
                if(!colOnes[j]) continue;
                if(mat[i][j]==1) count++;
            }
        }
        return count;
    }
};