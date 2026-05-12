class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int num : nums) {
            int sumOfDigits = 0;
            while(num) {
                sumOfDigits += num%10;
                num /= 10;
            }
            ans = min(ans,sumOfDigits);
        }
        return ans;
    }
};