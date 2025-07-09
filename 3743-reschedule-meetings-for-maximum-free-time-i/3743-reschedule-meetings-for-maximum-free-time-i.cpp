class Solution {
public:
    long long maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> gap(n+1);
        gap[0] = startTime[0];  
        for (int i = 1; i < n; ++i) {
            gap[i] = (long long)startTime[i] - endTime[i-1];
        }
        gap[n] = (long long)eventTime - endTime[n-1];
        int window = k + 1;
        long long sum = 0, ans = 0;
        for (int i = 0; i < window; ++i) {
            sum += gap[i];
        }
        ans = sum;
        for (int i = window; i <= n; ++i) {
            sum += gap[i] - gap[i - window];
            ans = max(ans, sum);
        }
        return ans;
    }
};