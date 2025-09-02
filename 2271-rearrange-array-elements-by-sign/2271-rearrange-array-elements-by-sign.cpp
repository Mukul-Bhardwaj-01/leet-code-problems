class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> negArr, posArr;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]<0) negArr.emplace_back(nums[i]);
            else posArr.emplace_back(nums[i]);
        }
        int i=0, j=0, k=0;
        while(k<nums.size() && i<posArr.size() && j<negArr.size()) {
            nums[k++]=posArr[i++];
            nums[k++]=negArr[j++];
        }
        return nums;
    }
};