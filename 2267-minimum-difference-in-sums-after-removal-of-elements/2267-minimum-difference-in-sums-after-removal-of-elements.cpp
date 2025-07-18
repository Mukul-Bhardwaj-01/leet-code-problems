class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int totalSize = 3 * n;
        vector<long long> left(2 * n), right(2 * n + 1);
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int i = 0; i < 2 * n; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n) {
                left[i] = sum;
            }
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        for (int i = totalSize - 1; i >= n; --i) {
            sum += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n) {
                right[i] = sum;
            }
        }
        long long res = LLONG_MAX;
        for (int i = n; i <= 2 * n; ++i) {
            res = min(res, left[i - 1] - right[i]);
        }
        return res;
    }
};