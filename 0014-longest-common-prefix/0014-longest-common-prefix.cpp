class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string first = strs[0], last = strs[n-1], result = "";
        int m = first.length()<last.length()?first.length():last.length();
        for(int i = 0; i<m; ++i) {
            if(first[i] == last[i]) {
                result+=first[i];
            }
            else break;
        }
        return result;
    }
};