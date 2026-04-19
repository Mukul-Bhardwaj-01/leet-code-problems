class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, res = 0, n = nums.size();
        for(int &i : nums) {
            if(i == 1) {
                res++;
                ans = max(ans,res);
            }
            else res = 0;
        }
        return ans;
    }
};