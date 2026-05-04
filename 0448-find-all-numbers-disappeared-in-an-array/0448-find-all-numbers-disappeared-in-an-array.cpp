class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> oneToN(n,false);
        for(int i = 0; i<n; ++i) {
            if(oneToN[nums[i]-1]) continue;
            oneToN[nums[i]-1] = true;
        }
        vector<int> ans;
        for(int i = 0; i<n; ++i) {
            if(!oneToN[i]) ans.push_back(i+1);
        }
        return ans;
    }
};