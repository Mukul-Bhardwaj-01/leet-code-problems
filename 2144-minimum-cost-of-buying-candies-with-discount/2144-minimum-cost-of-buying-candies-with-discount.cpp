class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(), [] (const int &a, const int &b) {
            return a>b;
        });
        int n = cost.size();
        int amount = 0;
        for(int i = 0; i<n; ++i) {
            if(i % 3 == 2) continue;
            amount += cost[i];
        }
        return amount;
    }
};