class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minEle = nums[0], maxEle = nums[0];
        for(int &i : nums) {
            minEle = min(minEle,i);
            maxEle = max(maxEle,i);
        }
        return gcd(maxEle,minEle);
    }
};