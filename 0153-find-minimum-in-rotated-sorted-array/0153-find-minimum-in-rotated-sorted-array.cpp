class Solution {
public:
    /*int BS(vector<int>& nums, int low, int high) {
        
    }*/
    int findMin(vector<int>& nums) {
        int minel = *min_element(nums.begin(),nums.end());
        return minel;
    }
};