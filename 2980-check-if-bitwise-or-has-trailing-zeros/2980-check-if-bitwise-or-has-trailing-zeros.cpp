class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(int i : nums) {
            if(i%2==0) cnt++;
            if(cnt == 2) return 1;
        }
        return 0;
    }
};