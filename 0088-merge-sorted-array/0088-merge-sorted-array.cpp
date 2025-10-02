class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i=0, j=0;
        while(i<m && j<n) {
            if(nums1[i]<=nums2[j]) temp.emplace_back(nums1[i++]);
            else temp.emplace_back(nums2[j++]);
        }
        while(i<m) temp.emplace_back(nums1[i++]);
        while(j<n) temp.emplace_back(nums2[j++]);
        nums1=temp;
    }
};