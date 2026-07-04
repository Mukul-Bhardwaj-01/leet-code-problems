class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), cnt = 0;
        // If all elements are 9
        for(int i = 0; i < n; ++i) {
            if(digits[i] == 9) cnt++;
        }
        if(cnt == n) {
            for(int &i : digits) i = 0;
            digits.push_back(0);
            digits[0] = 1;
            return digits;
        }
        // If not all elements are 9
        for(int i = n - 1; i >= 0; --i) {
            if(digits[i] < 9) {
                digits[i]++;
                break;
            }
            else digits[i] = 0;
        }
        return digits;
    }
};