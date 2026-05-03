class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        s = s + s;
        if(s.contains(goal)) return true;
        return false;
    }
};