class Solution {
public:
    int BS(vector<int>& nums, int low, int high) {
        int minEl = INT_MAX;
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
    int findMin(vector<int>& nums) {
        return BS(nums, 0, nums.size()-1);
    }
};