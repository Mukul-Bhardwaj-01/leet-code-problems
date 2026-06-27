class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for(auto &num : nums) freq[num]++;
        int ans = 0;
        if(freq[1] % 2) ans = freq[1];
        else ans = freq[1] - 1;

        freq.erase(1);

        for(auto &it : freq) {
            int res = 0;
            long long x = it.first;
            while(freq.find(x) != freq.end() && freq[x] > 1) {
                res += 2;
                x *= x;
            }
            ans = max(ans,res + (freq.find(x) != freq.end() ? 1 : -1));
        }
        return ans;
    }
};