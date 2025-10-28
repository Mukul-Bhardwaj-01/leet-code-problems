class Solution {
public:
    void shiftLeft(string& s) {
        s += s[0];
        s.erase(0,1);
    }
    bool rotateString(string s, string goal) {
        int n = s.length();
        int i = 0;
        while(i<n) {
            if(s!=goal) {
                shiftLeft(s);
                i++;
            }
            else return true;
        }
        return false;
    }
};