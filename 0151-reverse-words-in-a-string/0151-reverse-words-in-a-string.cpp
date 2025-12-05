class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        int n = (int)s.size();
        int i = 0;
        while (i < n && s[i] == ' ') i++;
        while (i < n) {
            string word;
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }
            if (!word.empty()) res.push_back(word);
            while (i < n && s[i] == ' ') i++;
        }
        if (res.empty()) return "";
        string ans;
        for (int k = (int)res.size() - 1; k >= 0; --k) {
            ans += res[k];
            if (k) ans += ' ';
        }
        return ans;
    }
};