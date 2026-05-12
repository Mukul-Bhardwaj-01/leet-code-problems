class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long totalWays = 0;
        for(int pens = 0; pens*cost1 <= total; pens++)
            totalWays += ((total - pens*cost1)/cost2 + 1);
        return totalWays;
    }
};