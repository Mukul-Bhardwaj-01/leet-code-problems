class Solution {
public:
    bool partitionValue(int i, int sum, int n, vector<int>& nums) {
        for(int k=0; k<=i; ++k) {
            sum-=2*nums[k];
        }
        if(sum%2==0) return 1;
        return 0;
    }
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), count = 0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0; i<n-1; ++i) {
            if(partitionValue(i,sum,n,nums)) count++;
            else continue;
        }
        return count;
    }
};