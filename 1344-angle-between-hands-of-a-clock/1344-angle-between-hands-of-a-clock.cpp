class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = 0.0;
        double minHandPos = (double)minutes/5;
        double hourHandPos = (double)hour + (double)minutes/60;
        if(hourHandPos >= 12) hourHandPos -= 12;
        double difference = abs(hourHandPos - minHandPos);
        ans = 30 * difference;
        ans = min(ans,360 - ans);
        return ans;
    }
};