class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), maxlen=0;
        unordered_set<int> st;
        for(int i : nums) st.insert(i);
        for(auto it : st) {
            if(st.find(it-1) == st.end()) {
                int count = 1, x = it;
                while(st.find(x+1)!=st.end()) {
                    count++;
                    x++;
                }
                maxlen = max(maxlen,count);
            }
        }
        return maxlen;
    }
};