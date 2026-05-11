class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sign = 1;
        int alternatingSum = 0;
        for(int &i : nums) {
            alternatingSum += (sign*i);
            sign *= -1;
        }
        return alternatingSum;
    }
};