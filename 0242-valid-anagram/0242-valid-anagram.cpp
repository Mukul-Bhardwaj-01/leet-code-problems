class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return 0;
        int ArrST[26] = {0};
        for(char c : s) ArrST[c - 'a']++;
        for(char c : t) ArrST[c - 'a']--;
        for(int i = 0; i<26; ++i) if(ArrST[i] != 0) return 0;
        return 1;
    }
};