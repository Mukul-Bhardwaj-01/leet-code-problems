class Solution {
public:
    int countOdds(int low, int high) {
        if((high-low)%2!=0);
        else if(high%2!=0) high++;
        else low++;
        return (high-low+1)/2;
    }
};