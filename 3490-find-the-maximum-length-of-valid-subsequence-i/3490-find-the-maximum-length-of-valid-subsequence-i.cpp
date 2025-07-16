class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int dp[2][2]={0};
        int ans=0;
        for(int num:nums) {
            int r=num%2;
            for(int y=0; y<2; ++y) {
                dp[r][y] = dp[y][r] + 1;
                ans=max(ans,dp[r][y]);
            }
        }
        return ans;
    }
};