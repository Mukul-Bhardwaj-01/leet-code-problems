class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> count(maxi + 1,0);
        for(auto &i : nums) {
            count[i]++;
        }
        vector<int> ans;
        int ind = 0;
        for(int i = 0; i <= maxi; ++i) {
            if(i < target && count[i] > 0) {
                ind += count[i];
            }
            else if(i == target) {
                for(int j = ind; j < ind + count[i]; ++j) {
                    ans.push_back(j);
                }
                break;
            }
        }
        return ans;
    }
};