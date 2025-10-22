class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        if(arr[0] > k) return k;
        if((arr[n-1]-n)<k) return (arr[n-1]+k-(arr[n-1]-n)); 
        while(low<=high) {
            int mid = low + (high - low)/2;
            int missingNos = arr[mid] - (mid+1);
            if(missingNos < k) low = mid + 1;
            else high = mid - 1;
        }
        //now, high and low point to adjacent places and high<low
        //int ans = arr[high] + (k - (arr[high] - (high+1)));
        //ans = (high + 1) + k
        //ans = low + k
        return (low + k);
    }
};