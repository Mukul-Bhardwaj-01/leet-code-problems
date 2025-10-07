class Solution {
public:
    int BS(vector<int>& nums, int t, int low, int high) {
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == t) return 1;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]) {
                if(nums[low]<=t && t<nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(nums[mid]<t && t<=nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
    return 0;
    }

    bool search(vector<int>& nums, int target) {
        return BS(nums, target, 0, nums.size()-1);
    }
};