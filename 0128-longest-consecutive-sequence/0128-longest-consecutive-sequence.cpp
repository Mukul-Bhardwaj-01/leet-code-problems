class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int k=1, n=nums.size(), maxlen=1;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-1; ++i) {
            if(nums[i]==nums[i+1]) continue;
            if(nums[i]+1==nums[i+1]) {
                k++;
                maxlen = max(maxlen,k);
            }
            else k=1;
        }
        return n>1?maxlen:(n==0?0:1);
    }
};