class Solution {
public:
    int BS(vector<int>& nums, int low, int high) {
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(nums[mid] != nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            //eliminate left half
            else if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 == 1 && nums[mid]==nums[mid-1]))
                low = mid + 1;
            //eliminate right half
            else high = mid - 1;
        }
        return -1;
    }
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[1] != nums[0]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        return BS(nums, 1, n-2);
    }
};