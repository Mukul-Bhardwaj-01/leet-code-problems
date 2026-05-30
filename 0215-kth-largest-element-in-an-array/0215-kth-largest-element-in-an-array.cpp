class Solution {
public:
    int partition(vector<int> &nums, int pivot, int low, int high) {
        int i = low, j = high;
        while(i<=j) {
            while(i <= high && nums[i] < pivot) i++;
            while(j >= low && nums[j] > pivot) j--;
            if(i<=j) {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        return j;
    }
    int quickselect(vector<int> &nums, int t, int low, int high) {
        while(low<high) {
            int pivot = nums[low + rand() % (high - low + 1)];
            int ind = partition(nums,pivot,low,high);

            if(t <= ind) high = ind;
            else low = ind + 1;
        }
        return nums[low];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int t = n - k;
        return quickselect(nums,t,0,n-1);
    }
};