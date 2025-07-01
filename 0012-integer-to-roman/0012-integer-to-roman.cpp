class Solution {
public:
    string intToRoman(int num) {
        string RomNum="";
        if(num>=1000) {
            int a = num/1000;
            for (int i=0; i<a; i++) RomNum.append("M");
            num %= 1000;
        }
        if (num>=100 && num<1000) {
            if (num>=500){
                if (num<900) {
                    RomNum.append("D");
                    num-=500;
                    int a = num/100;
                    for (int i=0; i<a; i++) RomNum.append("C");
                    num %= 100;
                }
                else {
                    RomNum.append("CM");
                    num %=100;
                }
            }
            else {
                if (num>=400) {
                    RomNum.append("CD");
                    num%=100;
                }
                else {
                    int a= num/100;
                    for (int i=0; i<a; i++) RomNum.append("C");
                    num%=100;
                }
            }
        }
        if(num>=10 && num<100) {
            if(num<40) {
                int a= num/10;
                for (int i=0; i<a; i++) RomNum.append("X");
                num%=10;
            }
            else if(num<50) {
                RomNum.append("XL");
                num%=10;
            }
            else if(num<90) {
                RomNum.append("L");
                num-=50;
                int a= num/10;
                for (int i=0; i<a; i++) RomNum.append("X");
                num%=10;
            }
            else {
                RomNum.append("XC");
                num%=10;
            }
        }
        if(num<10 && num>=1) {
            if(num<4) for (int i=0; i<num; i++) RomNum.append("I");
            else if(num==4) RomNum.append("IV");
            else if(num<9) {
                RomNum.append("V");
                num-=5;
                for (int i=0; i<num; i++) RomNum.append("I");
            }
            else RomNum.append("IX");
        }
        return RomNum;
    }
};