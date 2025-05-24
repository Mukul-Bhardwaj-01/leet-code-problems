class Solution {
public:
    int sumOfdigits(int a) {
        int sum = 0;
        while(a>0) {
            sum = sum + a%10;
            a = a/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int i;
        for (i=0; i< nums.size(); i++) {
            if (i==sumOfdigits(nums[i])) {
                break;
            }
        }
        if (i==nums.size()) {
            return -1;
        }
        else return i;
    }
};