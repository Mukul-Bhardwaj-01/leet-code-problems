class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minEle = INT_MAX, maxEle = INT_MIN;
        int minRow, maxRow;
        int n = arrays.size();
        for(int i = 0; i < n; ++i) {
            if(minEle > arrays[i][0]) {
                minEle = arrays[i][0];
                minRow = i;
            }
            if(maxEle < arrays[i].back()) {
                maxEle = arrays[i].back();
                maxRow = i;
            }
        }
        if(minRow != maxRow) return maxEle - minEle;

        int secondMin = INT_MAX, secondMax = INT_MIN;
        for(int i = 0; i < n; ++i) {
            if(i != minRow) {
                if(secondMin > arrays[i][0]) 
                    secondMin = arrays[i][0];
                if(secondMax < arrays[i].back()) 
                    secondMax = arrays[i].back();
            }
        }
        return max(maxEle - secondMin, secondMax - minEle);
    }
};