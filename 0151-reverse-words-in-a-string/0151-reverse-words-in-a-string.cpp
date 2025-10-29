class Solution {
public:
    string reverseWords(string s) {
        string res = ""; //Space = O(n) for output
        int n = s.length(), first = 0;
        for(int i = 0; i<n; ++i) { // Time = worst case O(n), average case: O(1)
            if(isspace(s[i])) first++;
            else break;
        }
        int start = n-1, end = n-1;
        while(start<=end && start>=0) { //Time = O(2n*k)
            while(start>=0 && !isalnum(s[start])) {
                start--; end--;
                if(start < 0) break;
            }
            while(start>=0 && isalnum(s[start])) {
                start--;
                if(start<0) break;
            }
            start++;
            string c = ""; 
            if(start > first) c = " ";
            res += s.substr(start, end - start + 1) + c;
            if(start >= 0) {
                start--; end = start;
            }
        }
        //TC = O(n^2) and SC = O(n)
        return res;
    }
};