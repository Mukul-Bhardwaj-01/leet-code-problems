class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minEle = INT_MAX, maxEle = INT_MIN;
        int minRow, maxRow;
        for(int i = 0; i < arrays.size(); ++i) {
            if(minEle > arrays[i][0]) {
                minEle = arrays[i][0];
                minRow = i;
            }
            if(maxEle < arrays[i][arrays[i].size() - 1]) {
                maxEle = arrays[i][arrays[i].size() - 1];
                maxRow = i;
            }
        }
        if(minRow != maxRow) return maxEle - minEle;

        int secondMin = INT_MAX, secondMax = INT_MIN;
        for(int i = 0; i < arrays.size(); ++i) {
            if(i != minRow) {
                if(secondMin > arrays[i][0]) 
                    secondMin = arrays[i][0];
                if(secondMax < arrays[i][arrays[i].size()-1]) 
                    secondMax = arrays[i][arrays[i].size() - 1];
            }
        }

        return max(abs(secondMin - maxEle), abs(secondMax - minEle));
    }
};