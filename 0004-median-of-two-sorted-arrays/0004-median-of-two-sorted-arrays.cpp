class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        while (i < m) nums.push_back(nums1[i++]);
        while (j < n) nums.push_back(nums2[j++]);

        int total = m + n;
        if (total % 2 == 0) {
            return (nums[total/2 - 1] + nums[total/2]) / 2.0;
        } else {
            return nums[total/2];
        }
    }
};