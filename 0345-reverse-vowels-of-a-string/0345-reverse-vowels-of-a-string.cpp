class Solution {
public:
    string reverseVowels(string s) {
        int low = 0, high = s.length()-1;
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        while(low<=high) {
            if(st.count(s[low]) && st.count(s[high])) swap(s[low++],s[high--]);
            else if(!st.count(s[low])) low++;
            else high--;
        }
        return s;
    }
};