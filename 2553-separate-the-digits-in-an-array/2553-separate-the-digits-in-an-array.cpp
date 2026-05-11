class Solution {
public:
    vector<int> separate(int &i) {
        vector<int> sep;
        while(i > 0) {
            sep.push_back(i%10);
            i = i/10;
        }
        reverse(sep.begin(),sep.end());
        return sep;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int &i : nums) {
            if(i < 10) {
                ans.push_back(i);
                continue;
            }
            vector<int> temp = separate(i);
            for(int & t : temp) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};