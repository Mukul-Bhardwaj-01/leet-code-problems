class Solution {
public:
    int get_gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n,0);
        int mx = INT_MIN;
        for(int i = 0; i < n; ++i) {
            mx = max(mx,nums[i]);
            prefixGcd[i] = gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        
        long long sum = 0;
        for(int i = 0; i < n/2; ++i) {
            sum += gcd(prefixGcd[i],prefixGcd[n - 1 - i]);
        }
        return sum;
    }
};