class Solution {
public:
    int binarySearch(vector<int>& A, int t, int low, int high) {
        int mid=(low+high)/2;
        if(low>high) return low;
        if(A[mid]==t) return mid;
        else if(A[mid]<t) 
            return binarySearch(A,t,mid+1,high);
        else 
            return binarySearch(A,t,low,mid-1);
    }
    int searchInsert(vector<int>& nums, int target) {
        int i=binarySearch(nums,target,0,nums.size()-1);
        return i;
    } 
};