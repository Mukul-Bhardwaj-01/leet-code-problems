class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_set<int> onSwitch;
        for(int &i : bulbs) {
            if(onSwitch.count(i)) onSwitch.erase(i);
            else onSwitch.insert(i);
        }
        vector<int> ans(onSwitch.begin(),onSwitch.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};