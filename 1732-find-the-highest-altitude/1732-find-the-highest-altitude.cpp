class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, currentAlt = 0;
        int n = gain.size();
        for(int i = 0; i<n; ++i) {
            currentAlt += gain[i];
            ans = max(ans,currentAlt);
        }
        return ans;
    }
};