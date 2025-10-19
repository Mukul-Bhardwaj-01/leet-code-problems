class Solution {
public:
    bool canEat(vector<int>& piles, long long k, long long h) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + k - 1) / k;  // ceil division
            if (hours > h) return false; // avoid unnecessary overflow
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1;
        long long right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canEat(piles, mid, h)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};