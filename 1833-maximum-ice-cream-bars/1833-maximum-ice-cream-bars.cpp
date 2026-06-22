class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size(), count = 0, i = 0;
        while(i < n && coins - costs[i] >= 0) {
            coins -= costs[i];
            i++;
            count++;
        }
        return count;
    }
};