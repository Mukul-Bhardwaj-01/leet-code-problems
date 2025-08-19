class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxfreq = 0;
        int r = 0, l = 0;
        long long windowSum = 0;   // ✅ separate running sum
        while (r < n) {
            windowSum += nums[r];  // ✅ expand window
            long long cost = 1LL * nums[r] * (r - l + 1) - windowSum; // ✅ correct cost
            while (cost > k) {     // ✅ shrink window if needed
                windowSum -= nums[l];
                l++;
                cost = 1LL * nums[r] * (r - l + 1) - windowSum;
            }
            maxfreq = max(maxfreq, r - l + 1);
            r++;
        }
        return maxfreq;  // ✅ return result
    }
};