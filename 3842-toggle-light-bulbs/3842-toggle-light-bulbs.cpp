class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        unordered_map<int,int> freqSwitch;
        for(int &i : bulbs) freqSwitch[i]++;
        for(auto &it : freqSwitch) {
            if((it.second) % 2 != 0) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};