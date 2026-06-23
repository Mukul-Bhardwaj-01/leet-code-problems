class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen1(nums1.begin(),nums1.end()), seen2(nums2.begin(),nums2.end());
        vector<int> res1,res2;
        for(int i : seen1) if(!seen2.count(i)) res1.push_back(i);
        for(int i : seen2) if(!seen1.count(i)) res2.push_back(i);
        return {res1, res2};
    }
};