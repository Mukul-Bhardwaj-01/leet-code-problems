class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0, cnt1=0, cnt2=0;
        for(int i : nums) {
            if(i==0) cnt0++;
            else if(i==1) cnt1++;
            else cnt2++;
        }
        int i=0;
        while(i<nums.size()) {
            if(i<cnt0) nums[i++]=0;
            else if(i>=cnt0 && i<cnt0+cnt1) nums[i++]=1;
            else nums[i++]=2;
        }      
    }
};