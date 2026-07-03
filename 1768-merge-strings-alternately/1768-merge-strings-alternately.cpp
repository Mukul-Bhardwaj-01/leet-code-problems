class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int i = 0, j = 0;
        string ans;
        ans.reserve(m + n);
        while(i < m && j < n) {
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        while(i < m) ans.push_back(word1[i++]);
        while(j < n) ans.push_back(word2[j++]);
        return ans;
    }
};