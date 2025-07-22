class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0, cursum = 0, maxsum = 0;
        unordered_set<int> seen;
        while (right < nums.size()) {
            if (!seen.count(nums[right])) {
                seen.insert(nums[right]);
                cursum += nums[right];
                maxsum = max(maxsum, cursum);
                right++;
            } else {
                seen.erase(nums[left]);
                cursum -= nums[left];
                left++;
            }
        }
        return maxsum;
    }
};