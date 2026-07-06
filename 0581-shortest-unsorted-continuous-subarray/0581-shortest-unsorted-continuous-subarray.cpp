class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < n - 1) {
            if(nums[i] > nums[i+1]) break;
            i++;
        }
        if(i == j) return 0;
        while(j > 0) {
            if(nums[j] < nums[j-1]) break;
            j--;
        }
        int minEl = *min_element(nums.begin() + i + 1, nums.end());
        int maxEl = *max_element(nums.begin(), nums.begin() + j);
        int finali = 0, finalj = n - 1;
        while(nums[finali] <= minEl) finali++;
        while(nums[finalj] >= maxEl) finalj--;
        return finalj - finali + 1;
    }
};
/*
{1,2,3,4}
 i     j i*/