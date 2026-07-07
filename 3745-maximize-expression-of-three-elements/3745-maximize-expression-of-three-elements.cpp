class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int firstMaxInd = max_element(nums.begin(),nums.end()) - nums.begin();
        int secondMaxInd = -1;
        if(firstMaxInd == 0) {
            secondMaxInd = max_element(nums.begin() + 1, nums.end()) - nums.begin();
        }
        else if(firstMaxInd == nums.size() - 1) {
            secondMaxInd = max_element(nums.begin(), nums.end() - 1) - nums.begin();
        }
        else {
            int t1 = max_element(nums.begin(), nums.begin() + firstMaxInd) - nums.begin();
            int t2 = max_element(nums.begin() + firstMaxInd + 1, nums.end()) - nums.begin();
            if(nums[t1] > nums[t2]) secondMaxInd = t1;
            else secondMaxInd = t2;
        }
        return nums[firstMaxInd] + nums[secondMaxInd] - *min_element(nums.begin(),nums.end());
    }
};