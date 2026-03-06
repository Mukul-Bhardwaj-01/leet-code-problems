class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<bool> rowOnes(m,0), colOnes(n,0);
        for(int i = 0; i<m; ++i) rowOnes[i] = (accumulate(mat[i].begin(),mat[i].end(),0) == 1);
        for(int j = 0; j<n; ++j) {
            int sum = mat[0][j];
            for(int i = 1; i<m; ++i) {
                sum+=mat[i][j];
                if(sum>1) break;
            }
            if(sum == 1) colOnes[j] = 1;
        }
        int count = 0;
        for(int i = 0; i<m; ++i) {
            for(int j = 0; j<n; ++j) {
                if(mat[i][j]==1 && rowOnes[i] && colOnes[j]) count++;
            }
        }
        return count;
    }
};