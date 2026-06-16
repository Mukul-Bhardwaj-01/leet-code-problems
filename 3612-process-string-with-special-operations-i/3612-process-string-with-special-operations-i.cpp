class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char &c : s) {
            if(isalpha(c)) res += c;
            else if(c == '*' && res.size()) res.pop_back();
            else if(c == '#') res += res;
            else reverse(res.begin(),res.end());
        }
        return res;
    }
};