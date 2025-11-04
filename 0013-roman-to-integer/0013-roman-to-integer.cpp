class Solution {
public:
    int romanToInt(string s) {
        int IntNum = 0;
        int i=0, n = s.length();
        while (i<n) {
            if(s[i]=='M') IntNum+=1000;
            else if(s[i]=='D') IntNum+=500;
            else if(s[i]=='C') {
                if(i+1<n && s[i+1]=='M') {
                    IntNum+=900;
                    i++;
                }
                else if(i+1<n && s[i+1]=='D') {
                    IntNum+=400;
                    i++;
                }
                else IntNum+=100;
            }
            else if(s[i]=='L') IntNum+=50;
            else if(s[i]=='X') {
                if (i+1<n && s[i+1]=='C') {
                    IntNum+=90;
                    i++;
                }
                else if(i+1<n && s[i+1]=='L') {
                    IntNum+=40;
                    i++;
                }
                else IntNum+=10;
            }
            else if(s[i]=='V') IntNum+=5;
            else {
                if(i+1<n && s[i+1]=='V') {
                    IntNum+=4;
                    i++;
                }
                else if(i+1<n && s[i+1]=='X') {
                    IntNum+=9;
                    i++;
                }
                else IntNum+=1;
            }
            i++;
        }
        return IntNum;
    }
};