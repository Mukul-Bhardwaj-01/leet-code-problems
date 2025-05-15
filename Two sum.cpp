class Solution {
public:
    void heapify(vector<pair<int, int>>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left].first > arr[largest].first)
            largest = left;
        if (right < n && arr[right].first > arr[largest].first)
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<pair<int, int>>& arr) {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        // Store value with original index
        for (int i = 0; i < n; ++i)
            arr.push_back({nums[i], i});

        heapSort(arr);  // Sort using value

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target)
                return {arr[left].second, arr[right].second};  // return indices
            else if (sum < target)
                ++left;
            else
                --right;
        }

        return {};  // If not found
    }
};