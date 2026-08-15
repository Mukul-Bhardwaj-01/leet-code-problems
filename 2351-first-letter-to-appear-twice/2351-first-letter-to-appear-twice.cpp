class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> freq(26,0);
        char ans;
        for(char &ch : s) {
            if(freq[ch - 97]) {
                ans = ch;
                break;
            }
            freq[ch - 97]++;
        }
        return ans;
    }
};