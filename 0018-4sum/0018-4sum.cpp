class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-3; ++i) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; ++j) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1, l = n-1;
                while(k<l) {
                    long long sum = nums[i] + nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum == target) {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        result.emplace_back(temp);
                        while(k<l && nums[k]==nums[k+1]) k++;
                        while(k<l && nums[l]==nums[l-1]) l--;
                        k++;
                        l--; 
                    }
                    else if(sum>target) {
                        while(k<l && nums[l]==nums[l-1]) l--;
                        l--;
                    }
                    else {
                        while(k<l && nums[k]==nums[k+1]) k++;
                        k++;
                    }
                }
            }
        }
        return result;
    }
};