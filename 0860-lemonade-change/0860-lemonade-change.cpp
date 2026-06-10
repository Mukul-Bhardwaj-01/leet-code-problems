class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0;
        for(int &i : bills) {
            if(i == 5) cnt5++;
            else if(i == 10) {
                cnt10++;
                if(cnt5 > 0) cnt5--;
                else return false;
            }
            else {
                if(cnt10 > 0 && cnt5 > 0) {
                    cnt10--;
                    cnt5--;
                }
                else if(cnt5 - 3 >= 0) cnt5-=3;
                else return false;
            }
        }
        return true;
    }
};