class Solution {
public:
    string reverseWords(string s) {
        while(s.length() > 0 && isspace(s[s.length() - 1])) s.pop_back();
        reverse(s.begin(),s.end());
        while(s.length() > 0 && isspace(s[s.length() - 1])) s.pop_back();
        string ans = "";
        int n = s.length();
        int i = 0, j = 0;
        while(j < n) {
            while(j < n && !isspace(s[j])) j++;
            string temp = s.substr(i,j-i);
            reverse(temp.begin(),temp.end());
            ans += temp + " ";
            i = j;
            while(i < n) {
                if(isspace(s[i])) i++;
                else {
                    j = i;
                    break;
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};