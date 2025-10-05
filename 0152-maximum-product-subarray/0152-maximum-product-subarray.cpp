class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxPr = INT_MIN;
        int prePr = 1, suffPr = 1;
        for(int i = 0; i<n; ++i) {
            if(prePr == 0) prePr = 1;
            if(suffPr == 0) suffPr =1;
            prePr *= nums[i];
            suffPr *= nums[n-1-i];
            maxPr = max(maxPr, max(prePr, suffPr));
        }
        return maxPr;
    }
};