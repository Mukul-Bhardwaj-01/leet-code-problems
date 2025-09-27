class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int el1, el2, count1 = 0, count2 = 0, n = nums.size();
        for(int i : nums) {
            if(count1 == 0 && el2!=i) {
                count1++; el1 = i;
            }
            else if(count2 == 0 && el1!=i) {
                count2++; el2 = i;
            }
            else if(i == el1) count1++;
            else if(i == el2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        if(count1!=0) {
            int freq1 = 0;
            for(int i : nums) {
                if(i == el1) freq1++;
            }
            if(freq1>n/3) res.emplace_back(el1);
        }
        if(count2!=0) {
            int freq2 = 0;
            for(int i : nums) {
                if(i == el2) freq2++;
            }
            if(freq2>n/3) res.emplace_back(el2);
        }
        return res;
    }
};