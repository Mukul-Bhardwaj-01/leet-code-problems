class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        if(nums.size()==1) {
            return nums[0];
        }
        int left=0,right=0,cursum=0,maxsum=0;
        while(right<nums.size()) {
            if(!seen.count(nums[right])) {
                seen.insert(nums[right]);
                cursum+=nums[right];
                right++;
                maxsum=max(maxsum,cursum);
            }
            else {
                while(seen.count(nums[right])) {
                    seen.erase(nums[left]);
                    cursum-=nums[left];
                    left++;
                }
            }
        }
        return maxsum;
    }
};