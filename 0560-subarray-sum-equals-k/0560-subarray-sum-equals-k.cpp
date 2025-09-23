class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        int presum=0, count=0;
        unordered_map<int, int> hash;
        hash[0]=1;
        for(int i=0; i<nums.size(); ++i) {
            presum+=nums[i];
            int rem = presum-k;
            count+=hash[rem];
            hash[presum]++;
        }
        return count;
    }
};