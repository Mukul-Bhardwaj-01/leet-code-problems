class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lesser = 0, equal = 0;
        for(int & i : nums) {
            if(i < target) lesser++;
            else if(i == target) equal++;
        }

        vector<int> ans(equal,0);
        for(int i = 0; i < equal; ++i) {
            ans[i] = i + lesser;
        }
        return ans;
    }
};