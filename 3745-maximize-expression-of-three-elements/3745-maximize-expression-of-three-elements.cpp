class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN;
        int c = INT_MAX;
        for (int x : nums) {
            c = min(c, x);
            if (x >= a) {
                b = a;
                a = x;
            }
            else if (x > b) b = x;
        }
        return a + b - c;
    }
};