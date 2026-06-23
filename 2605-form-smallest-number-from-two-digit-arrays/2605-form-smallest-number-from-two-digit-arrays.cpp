class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int min1 = 9, min2 = 9;
        int ans = INT_MAX;
        vector<bool> freq(10,false);
        for(int &i : nums1) {
            min1 = min(min1,i);
            freq[i] = true;
        }
        for(int &i : nums2) {
            min2 = min(min2,i);
            if(freq[i]) ans = min(ans,i);
        }
        ans = min({ans, min1*10 + min2, min2*10 + min1});
        return ans;
    }
};