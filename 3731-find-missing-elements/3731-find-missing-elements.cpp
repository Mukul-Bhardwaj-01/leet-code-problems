class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxEle = INT_MIN, minEle = INT_MAX;
        for(int & ele : nums) {
            maxEle = max(maxEle, ele);
            minEle = min(minEle, ele);
        }
        vector<bool> exists(maxEle - minEle + 1,false);
        for(int & ele : nums) {
            exists[ele - minEle] = true;
        }
        vector<int> ans;
        for(int i = 0; i < maxEle - minEle + 1; ++i) {
            if(!exists[i]) ans.push_back(i + minEle);
        }
        return ans;
    }
};