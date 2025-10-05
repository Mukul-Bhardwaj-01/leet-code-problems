class Solution {
public:
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
    int countReversePairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0, right = mid+1;
        for(int left = low; left<=mid; ++left) {
            while(right<=high && (long long)nums[left]>(long long)2*nums[right]) 
                right++;
            count+=right - (mid + 1);
        }
        return count;
    }
    int mergesort(vector<int>& nums, int low, int high) {
        int count = 0;
        if(low>=high) return count;
        int mid = (low + high)/2;
        count += mergesort(nums, low, mid);
        count += mergesort(nums, mid+1, high);
        count += countReversePairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums, 0, n-1);
    }
};