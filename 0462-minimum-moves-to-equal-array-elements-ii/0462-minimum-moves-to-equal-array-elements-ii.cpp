class Solution {
public:
    int partition(vector<int>&arr, int low, int high) {
        int pivot = arr[low];
        int i = low + 1, j = high;
        while(i<=j) {
            while(i<=high && arr[i] <= pivot) i++;
            while(j>low && arr[j] > pivot) j--;
            if(i < j) {
                swap(arr[i],arr[j]);
                i++; j--;
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }
    int quickSelect(vector<int>& arr, int low, int high, int targetIndex) {
        if(low == high) return arr[low];
        int pivotIndex = low + rand() % (high - low + 1);
        swap(arr[low], arr[pivotIndex]);
        int k = partition(arr,low,high);
        if(k == targetIndex) return arr[k];
        else if(k > targetIndex) return quickSelect(arr, low, k - 1, targetIndex);
        return quickSelect(arr, k + 1, high, targetIndex);
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int median = quickSelect(nums,0,n-1,n/2);
        for(int &i : nums) {
            ans += abs(i - median);
        }
        return ans;
    }
};