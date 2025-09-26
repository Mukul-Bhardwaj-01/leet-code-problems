class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; ++i) {
            vector<int> temp;
            long long t = 1;
            for(int j = 0; j <= i; ++j) {
                temp.push_back((int)t);
                t = t * (i - j) / (j + 1);
            }
            res.push_back(temp);
        }
        return res;
    }
};
