class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row-wise check O(n X n)
        for(auto &vec : board) {
            unordered_set<char> s1;
            for(auto &c : vec) {
                if(c == '.') continue;
                if(s1.count(c)) return false;
                s1.insert(c);
            }
        }
        //column-wise check O(n X n)
        for(int i = 0; i<9; ++i) {
            unordered_set<char> s2;
            for(int j = 0; j<9; ++j) {
                if(board[j][i] == '.') continue;
                if(s2.count(board[j][i])) return false;
                s2.insert(board[j][i]);
            }
        }
        //3 X 3 box wise checks O(n X n)
        for(int k = 0; k<3; ++k) {
            unordered_set<char> seen1, seen2, seen3;
            for(int i = k*3; i< k*3 + 3; ++i) {
                for(int j = 0; j<3; ++j) {
                    if(board[i][j] == '.') continue;
                    if(seen1.count(board[i][j])) return false;
                    seen1.insert(board[i][j]);
                }
                for(int j = 3; j<6; ++j) {
                    if(board[i][j] == '.') continue;
                    if(seen2.count(board[i][j])) return false;
                    seen2.insert(board[i][j]);
                }
                for(int j = 6; j<9; ++j) {
                    if(board[i][j] == '.') continue;
                    if(seen3.count(board[i][j])) return false;
                    seen3.insert(board[i][j]);
                }
            }
        }
        return true;
    }
};