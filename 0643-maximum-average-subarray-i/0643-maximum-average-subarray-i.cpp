class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = k-1;
        double sum = 0, maxsum;
        for(int i = 0; i<k; ++i) {
            sum+=nums[i];
        }
        maxsum = sum;
        while(right<n) {
            maxsum = max(sum, maxsum);
            right++;
            if(right<n) {
                sum = sum + nums[right] - nums[left];
                left++;
            }
        }
        return maxsum/k;
    }
};