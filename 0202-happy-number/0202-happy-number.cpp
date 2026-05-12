class Solution {
public:
    unordered_set<int> seen;
    bool check(int num) {
        int processed = 0;
        while(num > 0) {
            int a = num%10;
            processed += (a*a);
            num /= 10;
        }
        if(!seen.count(processed)) seen.insert(processed);
        else if(seen.count(processed) && processed == 1) return true;
        else if(seen.count(processed) && processed != 1) return false;
        return check(processed);
    }
    bool isHappy(int n) {
        return check(n);
    }
};