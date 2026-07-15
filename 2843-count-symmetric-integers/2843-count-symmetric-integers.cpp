class Solution {
public:
    bool symmetric(int x) {
        int n = to_string(x).length();
        if(n % 2) return false;
        int sum1 = 0;
        for(int i = 0; i < n/2; ++i) {
            sum1 += x%10;
            x /= 10;
        }
        for(int i = 0; i < n/2; ++i) {
            sum1 -= x%10;
            x /= 10;
        }
        return sum1 == 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; ++i) {
            if(symmetric(i)) ans++;
        }
        return ans;
    }
};