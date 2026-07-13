class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int i = 0, j = s.length() - 1;
        while(i < j) {
            while(!vowels.count(s[i])) {
                i++;
                if(i == s.length()) 
                    return s;
            }
            while(!vowels.count(s[j])) j--;
            if(i < j) {
                swap(s[i],s[j]);
                i++; j--;
            }
        }
        return s;
    }
};