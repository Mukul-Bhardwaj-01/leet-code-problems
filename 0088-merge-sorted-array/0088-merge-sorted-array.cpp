class Solution {
public:
    void swapIfGrt(vector<int>& nums1, vector<int>& nums2, int i1, int i2) {
        if(nums1[i1]>nums2[i2]) swap(nums1[i1],nums2[i2]);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m+n)/2 + (m+n)%2;
        while(gap > 0) {
            int left = 0, right = left + gap;
            while(right<m+n) {
                if(left<m && right>=m) {
                    swapIfGrt(nums1, nums2, left, right-m);
                }
                else if(right<m) {
                    swapIfGrt(nums1, nums1, left, right);
                }
                else {
                    swapIfGrt(nums2,nums2, left-m, right-m);
                }
                left++; right++;
            }
            if(gap == 1) break;
            gap = gap/2 + gap%2;
        }
        for(int i = m; i<m+n; ++i) {
            nums1[i] = nums2[i-m];
        }
    }
};