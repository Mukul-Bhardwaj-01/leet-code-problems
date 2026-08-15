class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> freq(26,0);
        for(char &ch : s) {
            if(freq[ch - 97]) return ch;
            freq[ch - 97]++;
        }
        return 'a';
    }
};