class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return 0;
        int countv = 0, countc = 0;
        for (char ch : word) {
            if (!isalnum(ch)) return 0;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                countv++;
            }
            else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                countc++;
            }
        }
        return (countv > 0 && countc > 0);
    }
};