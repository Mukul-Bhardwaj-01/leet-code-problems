class Solution {
public:
    string longestPalindrome(string s) {
        int a=0,b=0;
        vector<pair<int,int>> dp;
        for (int i=0; i<s.length(); i++) {
            expandFromCenter(i,i,s,dp);
            expandFromCenter(i,i+1,s,dp);
        }
        int max = dp[0].second - dp[0].first;
        for(int j=1; j<dp.size(); j++) {
            if(dp[j].second-dp[j].first>max) {
                max= dp[j].second-dp[j].first;
                a=dp[j].first;
                b=dp[j].second;
            }
        }
        return s.substr(a,b-a+1);
    }
    void expandFromCenter(int left, int right, const string& s, vector<pair<int,int>>& dp) {
        while(left>=0 && right<s.size() && s[left]==s[right]) {
            left--;
            right++;
        }
        dp.push_back({left+1,right-1});
    }
};