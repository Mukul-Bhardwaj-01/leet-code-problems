class Solution {
public:
    bool checkString(string s) {
        /*
        int i = 0, n = s.length();
        for(i; i<n; ++i) {
            if(s[i] == 'a') continue;
            break;
        }
        while(i<n) {
            if(s[i++] == 'b') continue;
            return false;
        }
        return true;
        */
        return s.find("ba") == string::npos;
    }
};