class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return 0;
        map<char,int> hashS, hashT; //Space O(2n)
        for(char c : s) hashS[c]++; //Time O(nlogn)
        for(char c : t) hashT[c]++; //Time O(nlogn)
        if(hashS == hashT) return 1; //Time O(n)
        return 0;
    }
};