class Solution {
public:
    vector<int> separate(int i) {
        vector<int> sep;
        while(i > 0) {
            sep.push_back(i%10);
            i = i/10;
        }
        return sep;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i : nums) {
            vector<int> temp = separate(i);
            int tempsize = temp.size();
            for(int t = tempsize - 1; t>=0; --t) {
                ans.push_back(temp[t]);
            }
        }
        return ans;
    }
};