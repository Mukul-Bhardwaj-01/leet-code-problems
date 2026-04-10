class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i<nums.size(); ++i) {
            hash[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it : hash) {
            if(it.second.size() >= 3) {
                int start = 0, end = 2;
                while(end < it.second.size()) {
                    ans = min(ans, 2*(it.second[end] - it.second[start]));
                    end++; start++;
                }
            }
        }
        ans = (ans != INT_MAX) ? ans : -1;
        return ans;
    }
};