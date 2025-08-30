class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> hash;
        for(auto it : nums) {
            hash[it]++;
        }
        for(auto it : hash) {
            if(it.second==1) return it.first;
        }
        return 0;
    }
};