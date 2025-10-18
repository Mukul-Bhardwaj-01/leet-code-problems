class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i : nums) hash[i]++;
        for(auto it : hash) if(it.second != 2) return it.first; 
        return 0;
    }
};