class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> eleInd;
        for(int i = 0; i < n; ++i)
            eleInd.push_back({nums[i], i});
        sort(eleInd.begin(), eleInd.end());
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            if(i > 0 && eleInd[i].first == eleInd[i - 1].first)
                ans[eleInd[i].second] = ans[eleInd[i - 1].second];
            else
                ans[eleInd[i].second] = i;
        }
        return ans;
    }
};