class Solution {
public:
    bool checkCapacityValid(vector<int>& weights, int n, int days, int cap) {
        int count = 1, weightSum = 0;
        for(int i = 0; i<n; ++i) {
            if(weightSum + weights[i] > cap) {
                count++;
                weightSum = 0;
            }
            weightSum+=weights[i];
            if(count > days) return 0;
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(checkCapacityValid(weights, n, days, mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};