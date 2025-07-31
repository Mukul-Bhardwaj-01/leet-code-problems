class Solution {
public:
    int longestPalindrome(string s) {
        int longest=s.length();
        bool odd=false;
        unordered_map<char,int> freq;
        for(char c : s) {
            freq[c]++;
        }
        for(auto p : freq) {
            if(p.second%2!=0) {
                --longest;
                odd=true;
            }
        }
        if(odd) ++longest;
        return longest;
    }
};