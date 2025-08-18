class Solution {
public:
    bool isPalindrome(string s) {
        string p = "";
        for(char c:s) {
            if(isalnum(c)) {
                if(isupper(c)) {
                    char a = tolower(c);
                    p+=a;
                }
                else p+=c;
            }
        }
        int i=0, n=p.length();
        while(i<n/2) {
            if(p[i]==p[n-1-i]) {
                i++;
            }
            else return 0;
        }
        return 1;
    }
};