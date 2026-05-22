class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int ele = nums[mid];
            if(ele == target) return mid;
            else if(ele > target) {
                if(ele >= nums[low]) {
                    if(nums[low] <= target) high = mid - 1;
                    else low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else {
                if(nums[low] <= ele) {
                    low = mid + 1;
                }
                else {
                    if(nums[high] >= target) low = mid + 1;
                    else high = mid - 1;
                }
            }
        }
        return -1;
    }
};