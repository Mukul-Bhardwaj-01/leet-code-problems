class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i<n-1) {
            if(nums[i] == nums[i+1]) i+=2;
            else break;
        }
        return nums[i];
    }
};