class Solution {
public:
  bool checkIfValid(vector<int>& nums, int threshold, int n, int d) {
    int sum = 0;
    for(int i = 0; i<n; ++i) {
      sum+=((nums[i]+d-1)/d);
      if(sum>threshold) return 0;
    }
    if(sum<=threshold) return 1;
    return 0;
  }
  int smallestDivisor(vector<int> &nums, int threshold) {
    int max = *max_element(nums.begin(),nums.end());
    int low = 1, high = max;
    while(low<=high) {
      int mid = low + (high - low)/2;
      if(checkIfValid(nums, threshold, nums.size(), mid)) high = mid - 1;
      else low = mid + 1;
    }
    return low;    
  }
};