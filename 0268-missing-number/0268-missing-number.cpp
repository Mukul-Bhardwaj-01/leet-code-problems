#include <numeric>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1=0, XOR2=0;
        for(int i=0; i<nums.size(); ++i) {
            XOR2^=nums[i];
            XOR1^=(i+1);
        }
        return XOR1^XOR2;
    }
};