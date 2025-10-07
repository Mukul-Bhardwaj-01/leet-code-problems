class Solution {
public:
    int firstO(vector<int>& nums, int t, int low, int high) {
        int first = -1;
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == t) {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] > t) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return first;
    }
    int lastO(vector<int>& nums, int t, int low, int high) {
        int last = -1;
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == t) {
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] > t) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        return {firstO(nums,target,low,high), lastO(nums,target,low,high)};
    }
};