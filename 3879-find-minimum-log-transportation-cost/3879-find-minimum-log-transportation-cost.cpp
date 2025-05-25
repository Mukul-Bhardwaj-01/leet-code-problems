class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
         long long cost = 0;
        auto minCut = [&](int length) -> long long {
            if (length <= k) return 0;
            long long minCost = LLONG_MAX;
            for (int i = 1; i < length; ++i) {
                int part1 = i;
                int part2 = length - i;
                if (part1 <= k && part2 <= k) {
                    long long currCost = 1LL * part1 * part2;
                    minCost = min(minCost, currCost);
                }
            }
            return minCost == LLONG_MAX ? 0 : minCost;
        };
        cost += minCut(n);
        cost += minCut(m);
        return cost;
    }
};