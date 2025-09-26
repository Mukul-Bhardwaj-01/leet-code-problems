class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int t = nums.size()/3;
        map<long long, int> hash;
        for(int i : nums) {
            hash[i]++;
            if (hash[i]>t && find(res.begin(), res.end(), i)==res.end()) res.emplace_back(i);
        }
        return res;
    }
};