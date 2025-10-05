class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxPr = 0;
        if(n == 1) return nums[0];
        for(int i = 0; i<n; ++i) {
            int curPr = 1;
            for(int j = i; j<n; ++j) {
                curPr*=nums[j];
                maxPr = max(maxPr, curPr);
            }
            
        }
        return maxPr;
    }
};