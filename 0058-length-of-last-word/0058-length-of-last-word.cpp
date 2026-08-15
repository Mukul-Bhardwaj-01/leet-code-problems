class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int high = n - 1;
        while(high >= 0) {
            if(!isspace(s[high])) break;
            high--;
        }
        int low = high;
        while(low >= 0) {
            if(isspace(s[low])) break;
            low--;
        }
        return high - low;
    }
};