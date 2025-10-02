class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i=m-1, j=0;
        while(i>=0 && j<n) {
            if(nums2[j]<=nums1[i]) swap(nums1[i--],nums2[j++]);
            else break;
        }
        sort(nums1.begin(),nums1.begin() + m);
        sort(nums2.begin(),nums2.end());
        for(int i = m; i<m+n; ++i) {
            nums1[i] = nums2[i-m];
        }
    }
};