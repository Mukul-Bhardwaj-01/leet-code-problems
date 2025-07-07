class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] > arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        mergeSort(arr, 0, n - 1);
        bool found = 0;
        int i = 0;
        while (!found && i < n) {
            int a = arr[i];
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == a) {
                    count++;
                }
            }
            if (count == a) {
                found = 1;
                return a;
            }
            i++;
        }
        return -1;
    }
};