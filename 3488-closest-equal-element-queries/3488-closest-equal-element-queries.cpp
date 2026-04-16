class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        for(int i = 0; i < n; i++) 
            pos[nums[i]].push_back(i);

        vector<int> ans;

        for(int q : queries) {
            auto &v = pos[nums[q]];

            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();

            int res = INT_MAX;

            int next = v[(idx + 1) % v.size()];
            int d1 = abs(next - q);
            res = min(res, min(d1, n - d1));
            int prev = v[(idx - 1 + v.size()) % v.size()];
            int d2 = abs(prev - q);
            res = min(res, min(d2, n - d2));
            ans.push_back(res);
        }
        return ans;
    }
};