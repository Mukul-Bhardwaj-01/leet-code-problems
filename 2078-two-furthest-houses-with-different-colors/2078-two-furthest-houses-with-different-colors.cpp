class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0, n = colors.size();
        int i = 1, start = colors[0], last = colors[n - 1];
        while(i < n) {
            if(colors[i] != start) {
                ans = max(ans,i);
            }
            i++;
        }
        i-=2;
        while(i >= 0) {
            if(colors[i] != last) {
                ans = max(ans,n - 1 - i);
            }
            i--;
        }
        return ans;
    }
};