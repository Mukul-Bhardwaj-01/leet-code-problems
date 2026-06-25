class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> countingTarget(n,0);
        int freqTarget = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == target) freqTarget++;
            countingTarget[i] = freqTarget;
        }
        int cnt = 0;
        for(int i = 0; i<n; ++i) {
            for(int j = i; j<n; ++j) {
                if(i == 0) {
                    if(2 * countingTarget[j] > j - i + 1) cnt++;
                }
                else {
                    if(2 * (countingTarget[j] - countingTarget[i-1]) > (j - i + 1)) cnt++;
                }
            }
        }
        return cnt;
    }
};
/*0,1,2,3,4,5,6,7
  1,2,3,2,2,5,2,8  target = 2
 {0,1,1,2,3,3,4,4}
*/