class Solution {
public:
    int BS(vector<int>& nums, int low, int high) {
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            //mid lies on the increasing slope, then a peak is on right 
            else if (nums[mid]>nums[mid-1]) low = mid + 1;
            //mid lies on the decreasing slope, then a peak is on left 
            else high = mid - 1;
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        return BS(nums, 1, n-2);
    }
};