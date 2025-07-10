class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1);

        // 1. Compute all free time gaps
        gaps[0] = startTime[0];
        for (int i = 1; i < n; ++i) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        gaps[n] = eventTime - endTime[n - 1];

        // 2. Compute prefix and suffix max arrays
        vector<int> maxLeft(n + 1), maxRight(n + 1);
        maxLeft[0] = gaps[0];
        for (int i = 1; i <= n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], gaps[i]);
        }
        maxRight[n] = gaps[n];
        for (int i = n - 1; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], gaps[i]);
        }

        // 3. Try rescheduling each meeting
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int currDur = endTime[i] - startTime[i];
            int adjacent = gaps[i] + gaps[i + 1];
            int bestOtherGap = 0;

            if (i > 0) {
                bestOtherGap = max(bestOtherGap, maxLeft[i - 1]);
            }
            if (i + 2 <= n) {
                bestOtherGap = max(bestOtherGap, maxRight[i + 2]);
            }

            int totalFree = adjacent + (currDur <= bestOtherGap ? currDur : 0);
            ans = max(ans, totalFree);
        }

        return ans;
    }
};
