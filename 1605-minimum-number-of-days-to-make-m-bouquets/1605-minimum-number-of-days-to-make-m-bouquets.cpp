class Solution {
public:
    bool checkDay(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, bouquets = 0;
        for(int i = 0; i<bloomDay.size(); ++i) {
            if(bloomDay[i] <= day) count++;
            else {
                bouquets += (count/k);
                count = 0;
            }
        }
        bouquets += (count/k);
        if(bouquets >= m) return 1;
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*(long long)k > bloomDay.size()) return -1;
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int min = *min_element(bloomDay.begin(), bloomDay.end());
        if((long long)m*(long long)k == bloomDay.size()) return max;
        int low = min, high = max, ans = -1;
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(checkDay(bloomDay,m,k,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};