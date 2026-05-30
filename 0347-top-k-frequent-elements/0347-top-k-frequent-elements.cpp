class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i : nums) {
            freq[i]++;
        }
        vector<pair<int,int>> freqVec(freq.begin(),freq.end());
        vector<int> ans(k);
        sort(freqVec.begin(),freqVec.end(), [] (const auto & pair1, const auto & pair2) {
            return pair1.second > pair2.second;
        });
        for(int i = 0; i < k; ++i) {
            ans[i] = freqVec[i].first;
        }
        return ans;
    }
};