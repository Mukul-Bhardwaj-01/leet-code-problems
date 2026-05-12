class Solution {
public:
    int sumOfDigits(int num) {
        int res = 0;
        while(num > 0) {
            res += num%10;
            num /= 10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int num : nums)
            ans = min(ans,sumOfDigits(num));
        return ans;
    }
};