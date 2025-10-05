class Solution {
public:
    int count = 0;
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid+1;
        while(left<=mid && right<=high) {
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=high) temp.push_back(nums[right++]);
        for(int i = low; i<=high; ++i) {
            nums[i] = temp[i-low];
        }
    }
    void countReversePairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid+1;
        for(int left = low; left<=mid; ++left) {
            while(right<=high && (long long)nums[left]>(long long)2*nums[right]) 
                right++;
            count+=right - (mid + 1);
        }
    }
    void mergesort(vector<int>& nums, int low, int high) {
        if(low>=high) return;
        int mid = (low + high)/2;
        mergesort(nums, low, mid);
        mergesort(nums, mid+1, high);
        countReversePairs(nums, low, mid, high);
        merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n-1);
        return count;
    }
};