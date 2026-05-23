class Solution {
public:
    bool check(vector<int>& nums) {
        int drop = 0, n = nums.size();
        for(int i = 0; i<n; ++i) {
            if(nums[i] > nums[(i+1) % n]) drop++;
            if(drop == 2) break;
        }
        return drop<=1;
    }
};