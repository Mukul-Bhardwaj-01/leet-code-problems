class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        int n = s.length();
        int start = 0;
        while(start<n) {
            if(isspace(s[start])) start++;
            else break;
        }
        while(start<n) {
            string word = "";
            while(start<n && isalnum(s[start])) {
                word+=s[start];
                start++;
            }
            res.push_back(word);
            while(start<n && isspace(s[start])) start++;
        }
        string resStr = "";
        for(int i = res.size()-1; i>=0; --i) {
            resStr += (res[i] + " ");
        }
        resStr.pop_back();
        return resStr;
    }
};