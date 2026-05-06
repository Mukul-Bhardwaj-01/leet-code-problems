class Solution {
public:
    void adjustRow(vector<char>& arr, int n) {
        int i = n - 1;
        int possiblePos = INT_MIN;
        while(i >= 0) {
            if(arr[i] == '.') possiblePos = max(possiblePos,i);
            else if(arr[i] == '#') {
                if(possiblePos >= 0) {
                    swap(arr[i], arr[possiblePos]);
                    possiblePos--;
                    i = possiblePos;
                }
            }
            else {
                possiblePos = INT_MIN;
            }
            i--;
        }
        return;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        for(auto& vec : boxGrid) {
            adjustRow(vec,n);
        }
        vector<vector<char>> res(n,vector<char>(m));
        for(int i = 0; i<m; ++i) {
            for(int j = 0; j<n; ++j) {
                res[j][m-1-i] = boxGrid[i][j];
            }
        }
        return res;
    }
};