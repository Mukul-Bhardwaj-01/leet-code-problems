class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPr = 0, i=1, minVal = prices[0];
        int n = prices.size();
        while(i<n) {
            if(minVal > prices[i]) minVal = min(minVal, prices[i]);
            maxPr = max(maxPr, prices[i]-minVal);
            i++;  
        }
        return maxPr;
    }
};