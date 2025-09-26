class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int t = nums.size()/3;
        map<long long, int> hash;
        for(int i : nums)
            hash[i]++;
        for(auto it : hash)
            if(it.second > t) res.emplace_back(it.first);
        return res;
    }
};