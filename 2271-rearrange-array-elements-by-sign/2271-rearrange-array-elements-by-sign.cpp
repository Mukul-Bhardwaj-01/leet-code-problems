class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int k=0, l=1, n=nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; ++i) {
            if(nums[i]>0) {
                ans[k] = nums[i];
                k+=2;
            }
            else {
                ans[l] = nums[i];
                l+=2;
            }
        }
        return ans;
    }
};