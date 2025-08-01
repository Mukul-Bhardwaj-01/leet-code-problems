class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        // Add the first row
        res.push_back({1});

        for (int i = 1; i < numRows; ++i) {
            vector<int> row(i + 1, 1);  // Initialize row with 1s
            for (int j = 1; j < i; ++j) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(row);
        }

        return res;
    }
};
