class Solution {
public:
    bool toCheck(vector<int>& nums, int n, int k, int sum) {
        int curSum = 0, count = 1;
        for(int i = 0; i<n; ++i) {
            if(curSum + nums[i] > sum) {
                count++;
                if(count > k) return 0;
                curSum = 0;
            }
            curSum+=nums[i];
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(toCheck(nums,n,k,mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};