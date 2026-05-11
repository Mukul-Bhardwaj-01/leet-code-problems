class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int &i : nums) {
            if(i < 10) {
                ans.push_back(i);
                continue;
            }
            string s = to_string(i);
            for(char &c : s) ans.push_back(c - '0');
        }
        return ans;
    }
};