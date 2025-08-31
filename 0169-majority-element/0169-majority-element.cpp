class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> hash;
        for(int i:nums) hash[i]++;
        for(auto it:hash) {
            if(it.second>n/2) {
                return it.first;
            }
        }
        return 0; 
    }
};