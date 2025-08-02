class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;

        for (int b : basket1) freq[b]++;
        for (int b : basket2) freq[b]--;

        vector<int> a, b;
        int mini = INT_MAX;

        for (auto &[x, f] : freq) {
            if (f % 2 != 0) return -1; // can't be balanced
            int half = abs(f) / 2;
            mini = min(mini, x);
            if (f > 0) a.insert(a.end(), half, x);
            else if (f < 0) b.insert(b.end(), half, x);
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        long long cost = 0;
        for (int i = 0; i < a.size(); i++) {
            cost += min(2LL * mini, (long long)min(a[i], b[i]));
        }

        return cost;
    }
};