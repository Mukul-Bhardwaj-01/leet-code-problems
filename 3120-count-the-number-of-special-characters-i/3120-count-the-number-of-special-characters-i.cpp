class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(52,0);
        for(char &c : word) {
            if(c <= 90) {
                if(freq[c-65] == 0) freq[c-65] = 1;
            }
            else {
                if(freq[c-71] == 0) freq[c-71] = 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i<26; ++i) {
            if(freq[i] != 0 && freq[i+26] != 0) cnt++; 
        }
        return cnt;
    }
};