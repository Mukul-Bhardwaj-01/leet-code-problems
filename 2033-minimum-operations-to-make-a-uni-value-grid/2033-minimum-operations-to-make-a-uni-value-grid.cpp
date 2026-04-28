class Solution {
public:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[left];
        int i = left+1, j = right;
        while(i <= j) {
            while(i <= right && arr[i] < pivot) i++;
            while(j > left && arr[j] >= pivot) j--;
            if(i<j) swap(arr[i],arr[j]);
        }
        swap(arr[left],arr[j]);
        return j;
    }

    int quickSelect(vector<int>& arr, int left, int right, int k) {
        if (left == right) return arr[left];
        int pivotIndex = left + rand() % (right - left + 1);
        swap(arr[left], arr[pivotIndex]);
        int pos = partition(arr, left, right);
        if (pos == k) return arr[pos];
        if (pos > k) return quickSelect(arr, left, pos - 1, k);
        return quickSelect(arr, pos + 1, right, k);
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m*n;
        vector<int> grid1D(size, 0);
        for(int i = 0; i<m; ++i) {
            for(int j = 0; j<n; ++j)
                grid1D[i*n + j] = grid[i][j];
        }
        int median = quickSelect(grid1D, 0, size - 1, size / 2);
        int res = 0;
        for(int &i : grid1D) {
            if(abs(i - median) % x != 0) return -1;
            res += (abs(i - median)/x);
        }
        return res;
    }
};