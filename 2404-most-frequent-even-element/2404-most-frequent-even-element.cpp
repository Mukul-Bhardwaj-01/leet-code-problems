class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int ans = INT_MAX, freq = 0;
        unordered_map<int,int> evenFreq;
        for(int &i : nums) {
            if(i % 2) continue;
            evenFreq[i]++;
        }
        if(evenFreq.size() == 0) return -1;
        for(auto &it : evenFreq) {
            if(it.second > freq) {
                freq = it.second;
                ans = it.first;
            }
            else if(it.second == freq) {
                ans = min(ans,it.first);
            }
        }
        return ans;
    }
};