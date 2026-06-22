class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxEle = *max_element(costs.begin(),costs.end());
        vector<int> freq(maxEle + 1,0);
        for(int &i : costs) {
            freq[i]++;
        }
        int i = 0, count = 0;
        while(i < maxEle + 1) {
            if(freq[i] == 0) i++;
            else {
                if(coins < i) return count;
                else {
                    count++;
                    coins -= i;
                    freq[i]--;
                }
            }
        }
        return count;
    }
};