class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m-1;
        if(m == 1) return {0, (int)(max_element(mat[0].begin(),mat[0].end()) - mat[0].begin())};
        if(n == 1) {
            int maxx = 0, i = 0;
            for(i = 0; i<m; ++i) {
                if(mat[i][0] > mat[maxx][0]) maxx = i;
            }
            return {maxx,i};
        }
        while(low<=high) {
            int mid = (low + high)/2;
            int maxi = max_element(mat[mid].begin(),mat[mid].end()) - mat[mid].begin();
            if(mid == 0) {
                if(mat[mid][maxi] > mat[mid+1][maxi]) return {mid,maxi};
                else low = mid + 1;
            }
            else if(mid == m-1) {
                if(mat[mid][maxi] > mat[mid-1][maxi]) return {mid,maxi};
                else high = mid - 1;
            }
            else if(mat[mid][maxi] > mat[mid-1][maxi] && mat[mid][maxi] > mat[mid+1][maxi]) return {mid,maxi};
            else if(mat[mid][maxi] > mat[mid-1][maxi] && mat[mid][maxi] < mat[mid+1][maxi]) low = mid + 1;
            else if(mat[mid][maxi] < mat[mid-1][maxi] && mat[mid][maxi] > mat[mid+1][maxi]) high = mid - 1;
            else {
                if(mat[mid-1][maxi] > mat[mid+1][maxi]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return {-1,-1};
    }
};