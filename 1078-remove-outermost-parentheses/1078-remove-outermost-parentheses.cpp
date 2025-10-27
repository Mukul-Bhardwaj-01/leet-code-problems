class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        for(int i = 0; i<s.length(); ++i) {
            if(s[i] == '(') {
                cnt++;
                if(cnt>1) ans+='(';
            }
            else if(s[i] == ')') {
                cnt--;
                if(cnt>0) ans+=')';
            }
        }
        return ans;
    }
};