class Solution {
public:
    int maxOr = 0, count = 0;
    void dfs(vector<int>& nums, int idx, int currOr) {
        if (idx == nums.size()) {
            if (currOr == maxOr) count++;
            return;
        }
        // Include nums[idx]
        dfs(nums, idx + 1, currOr | nums[idx]);
        // Exclude nums[idx]
        dfs(nums, idx + 1, currOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxOr |= num;
        }
        dfs(nums, 0, 0);
        return count;
    }
};