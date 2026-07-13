class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int left = 1, right = 1;
        for(int i = 1; i < n; ++i) {
            ans[i] = ans[i] * left * nums[i-1];
            left = ans[i];
        }
        for(int i = n-2; i >= 0; --i) {
            ans[i] = ans[i] * right * nums[i+1];
            right *= nums[i+1];
        }
        return ans;
    }
};