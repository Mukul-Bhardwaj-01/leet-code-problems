class Solution {
public:
    bool equal(vector<vector<int>>& mat, vector<vector<int>>& target, const int &n) {
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<n; ++j) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    void rotateClockWise(vector<vector<int>>& mat, const int &n) {
        //transpose
        for(int i = 0; i<n; ++i) {
            for(int j = i+1; j<n; ++j) {
                swap(mat[i][j],mat[j][i]);
            }
        }
        //mirror about vertical to obtain 90 degree clockwise rotation of original mat
        for(int k = 0; k<n; ++k) {
            int i = 0, j = n-1;
            while(i<j) {
                swap(mat[k][i++],mat[k][j--]);
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int a = 0;
        int n = mat.size();
        while(a<4) {
            if(equal(mat,target,n)) return true;
            rotateClockWise(mat, n);
            a++;
        }
        return false;
    }
};