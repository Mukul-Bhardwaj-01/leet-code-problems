class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0, ind = 0;
        vector<int> lesser, greater;
        for(int &i : nums) {
            if(i > pivot) greater.push_back(i);
            else if(i < pivot) lesser.push_back(i);
            else cnt++;
        }
        for(int i = 0; i < lesser.size(); ++i) nums[ind++] = lesser[i];
        while(cnt--) nums[ind++] = pivot;
        for(int i = 0; i < greater.size(); ++i) nums[ind++] = greater[i];
        return nums;
    }
};