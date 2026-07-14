class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int i = 0, n = chars.size();
        while(i < n) {
            s += chars[i];
            i++;
            int cnt = 1;
            while(i < n && chars[i] == chars[i-1]) {
                cnt++;
                i++;
            }
            if(cnt > 1) {
                s += to_string(cnt);
            }
        }
        for(int j = 0; j < s.length(); ++j) {
            chars[j] = s[j];
        }
        return s.length();
    }
};