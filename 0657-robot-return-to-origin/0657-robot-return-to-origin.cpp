class Solution {
public:
    bool judgeCircle(string moves) {
        int moveUD = 0, moveLR = 0;
        for(char c : moves) {
            if(c == 'U') moveUD++;
            else if(c == 'D') moveUD--;
            else if(c == 'R') moveLR++;
            else moveLR--;
        }
        return moveUD == 0 && moveLR == 0;
    }
};