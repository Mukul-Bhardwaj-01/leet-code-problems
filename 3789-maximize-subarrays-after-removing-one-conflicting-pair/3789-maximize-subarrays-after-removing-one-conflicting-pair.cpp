class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflicts) {
        // Step 1: Store conflict edges in an adjacency list (only right->left mapping)
        vector<vector<int>> conflictList(n + 1);
        for (auto& c : conflicts) {
            int a = c[0], b = c[1];
            if (a > b) swap(a, b);  // Ensure a < b
            conflictList[b].push_back(a);  // Only store left endpoints for each right
        }

        long long totalValid = 0;
        int maxLeft = 0, secondMaxLeft = 0;
        vector<long long> gain(n + 1, 0);

        // Step 2: Traverse all positions from 1 to n
        for (int right = 1; right <= n; ++right) {
            for (int left : conflictList[right]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }

            // Without removing any conflict
            totalValid += (right - maxLeft);

            // Potential gain if we remove the most limiting left
            gain[maxLeft] += (maxLeft - secondMaxLeft);
        }

        // Step 3: Add max possible gain by removing one conflict
        long long maxGain = *max_element(gain.begin(), gain.end());
        return totalValid + maxGain;
    }
};
