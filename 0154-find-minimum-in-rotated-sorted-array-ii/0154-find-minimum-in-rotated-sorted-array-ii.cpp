class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int minEl = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low)/2;
            minEl = min(minEl, nums[mid]);
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid]) {
                minEl = min(minEl,nums[low]);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return minEl;
    }
};