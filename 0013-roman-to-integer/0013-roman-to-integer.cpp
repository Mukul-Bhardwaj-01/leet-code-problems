class Solution {
public:
    int romanToInt(string s) {
        int IntNum = 0;
        int i=0;
        while (i<s.length()) {
            if(s[i]=='M') {
                IntNum+=1000;
                i++;
            }
            if(s[i]=='D') {
                IntNum+=500;
                i++;
            }
            if(s[i]=='C') {
                if(s[i+1]=='M') {
                    IntNum+=900;
                    i+=2;
                }
                else if(s[i+1]=='D') {
                    IntNum+=400;
                    i+=2;
                }
                else {
                    IntNum+=100;
                    i++;
                }
            }
            if(s[i]=='L') {
                IntNum+=50;
                i++;
            }
            if(s[i]=='X') {
                if (s[i+1]=='C') {
                    IntNum+=90;
                    i+=2;
                }
                else if(s[i+1]=='L') {
                    IntNum+=40;
                    i+=2;
                }
                else {
                    IntNum+=10;
                    i++;
                }
            }
            if(s[i]=='V') {
                IntNum+=5;
                i++;
            }
            if(s[i]=='I') {
                if(s[i+1]=='V') {
                    IntNum+=4;
                    i+=2;
                }
                else if(s[i+1]=='X') {
                    IntNum+=9;
                    i+=2;
                }
                else {
                    IntNum+=1;
                    i++;
                }
            }
        }
        return IntNum;
    }
};