class Solution {
public:
    long long maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        // 1) Build the gaps array of length n+1
        //    gap[0] = time before first meeting
        //    gap[i] = startTime[i] - endTime[i-1]  for 1 <= i < n
        //    gap[n] = eventTime - endTime[n-1]
        vector<long long> gap(n+1);
        gap[0] = startTime[0];  
        for (int i = 1; i < n; ++i) {
            gap[i] = (long long)startTime[i] - endTime[i-1];
        }
        gap[n] = (long long)eventTime - endTime[n-1];

        // 2) We can eliminate up to k gaps by “shifting” the k meetings between them,
        //    which leaves one continuous block equal to the sum of (k+1) consecutive gaps.
        //    So we look for the maximum sum of any window of size k+1 in gap[].
        int window = k + 1;
        long long sum = 0, ans = 0;
        // initial window sum
        for (int i = 0; i < window; ++i) {
            sum += gap[i];
        }
        ans = sum;
        // slide it
        for (int i = window; i <= n; ++i) {
            sum += gap[i] - gap[i - window];
            ans = max(ans, sum);
        }
        return ans;
    }
};
