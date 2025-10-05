class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPr = 0;
        int n = prices.size();
        int minVal = prices[0];
        int i =1;
        while(i<n) {
            if(minVal > prices[i]) minVal = min(minVal, prices[i]);
            maxPr = max(maxPr, prices[i]-minVal);
            i++;  
        }
        return maxPr;
    }
};