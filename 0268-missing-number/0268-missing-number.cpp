#include <numeric>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n*(n+1)/2;
        int given = 0;
        for(int i=0; i<n; ++i) given+=nums[i];
        int missing = total - given;
        return missing;
    }
};