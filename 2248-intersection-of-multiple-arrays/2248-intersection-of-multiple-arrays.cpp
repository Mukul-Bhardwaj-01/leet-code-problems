class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> freq(1001,0);
        for(auto &vec : nums) {
            for(int &i : vec) {
                freq[i]++;
            }
        }
        vector<int> res;
        for(int i = 0; i < 1001; ++i) {
            if(freq[i] == nums.size()) res.push_back(i);
        }
        return res;
    }
};