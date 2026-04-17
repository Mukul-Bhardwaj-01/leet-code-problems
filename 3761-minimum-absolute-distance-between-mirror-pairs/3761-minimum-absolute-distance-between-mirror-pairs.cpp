class Solution {
public:
    int rev(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int target = rev(nums[i]);
            if (!mp.count(target)) continue;
            auto &vec = mp[target];
            auto it = upper_bound(vec.begin(), vec.end(), i);
            if (it != vec.end()) {
                ans = min(ans, *it - i);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};