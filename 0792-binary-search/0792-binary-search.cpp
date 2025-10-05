class Solution {
public:
    int BS(vector<int>& nums, int low, int high, int target) {
        if(low>high) return -1;
        while(low<=high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]>target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return BS(nums, 0, nums.size()-1, target);
    }
};