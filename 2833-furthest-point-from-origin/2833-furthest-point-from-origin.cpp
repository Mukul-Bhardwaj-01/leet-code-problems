class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int cntR = 0, cntL = 0, cnt_ = 0;
        for(char &c : moves) {
            if(c == 'L') cntL++;
            else if(c == 'R') cntR++;
            else cnt_++;
        }
        return abs(cntL - cntR) + cnt_;
    }
};