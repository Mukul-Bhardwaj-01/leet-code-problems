class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minEl = nums[0];
        for(int i = 0; i<n-1; ++i) {
            if(nums[i] <= nums[i+1]) continue;
            minEl = nums[i+1];
            break;
        }
        return minEl;
    }
};