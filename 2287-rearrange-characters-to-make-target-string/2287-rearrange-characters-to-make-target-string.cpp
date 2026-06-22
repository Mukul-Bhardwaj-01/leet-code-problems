class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> sFreq(26,0), targetFreq(26,0);
        for(char &c : s) {
            sFreq[c - 'a']++;
        }
        for(char &c : target) {
            targetFreq[c - 'a']++;
        }
        for(int i = 0; i<26; ++i) {
            if(targetFreq[i] == 0) sFreq[i] = INT_MAX;
            else {
                sFreq[i] /= targetFreq[i];
            }
        }
        return *min_element(sFreq.begin(),sFreq.end());
    }
};