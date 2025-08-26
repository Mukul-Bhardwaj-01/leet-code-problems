class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*int i=0;
        for(int j=1;j<nums.size();++j) {
            if(nums[j]!=nums[i]) {
                nums[++i]=nums[j];
            }
        }
        return i+1; */
        set<int> s;
        for(int i : nums) {
            s.insert(i);
        }
        int i=0;
        for(auto it: s) {
            nums[i] = it;
            i++;
        }
        return i;
    }
};