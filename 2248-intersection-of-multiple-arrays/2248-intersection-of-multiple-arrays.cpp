class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> freq;
        for(auto &vec : nums) {
            for(int &i : vec) {
                freq[i]++;
            }
        }
        vector<int> res;
        for(auto &it : freq) {
            if(it.second == nums.size()) res.push_back(it.first);
        }
        sort(res.begin(),res.end());
        return res;
    }
};