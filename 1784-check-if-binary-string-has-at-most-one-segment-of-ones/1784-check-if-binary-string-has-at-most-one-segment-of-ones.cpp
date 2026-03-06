class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos; //npos means no position or not found in the string
    }
};