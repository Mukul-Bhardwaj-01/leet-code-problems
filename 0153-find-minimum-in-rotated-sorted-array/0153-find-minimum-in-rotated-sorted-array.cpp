class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, minEl = INT_MAX;
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(nums[low] <= nums[mid]) {
                minEl = min(minEl,nums[low]);
                low = mid + 1;
            }
            else {
                minEl = min(minEl,nums[mid]);    
                high = mid - 1;
            }
        }
        return minEl;
    }
};