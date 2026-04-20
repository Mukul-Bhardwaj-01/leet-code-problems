class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for(int i = 0; i<n-1; ++i) {
            for(int j = i + 1; j<n; ++j) {
                if(colors[j] != colors[i]) ans = max(ans, j - i);
            }
        }
        return ans;
    }
};