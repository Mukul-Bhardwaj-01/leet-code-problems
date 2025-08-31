class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            int rem = target-nums[i];
            if(hash.find(rem)!=hash.end())
                return {i,hash[rem]};
            hash[nums[i]]=i;
        }
        return {};
    }
};