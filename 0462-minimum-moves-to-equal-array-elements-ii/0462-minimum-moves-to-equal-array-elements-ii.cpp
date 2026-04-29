class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(),nums.end());
        int median = nums[n/2];
        for(int &i : nums) {
            ans += abs(i - median);
        }
        return ans;
    }
};