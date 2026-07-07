class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1) {
            int max1stInd = max_element(stones.begin(),stones.end()) - stones.begin();
            int temp1Ind = max_element(stones.begin(), stones.begin() + max1stInd) - stones.begin();
            int temp2Ind = max_element(stones.begin() + max1stInd + 1, stones.end()) - stones.begin();
            int max2ndInd = -1;
            if(max1stInd == 0) max2ndInd = temp2Ind;
            else if(max1stInd == stones.size() - 1) max2ndInd = temp1Ind;
            else if(stones[temp1Ind] > stones[temp2Ind]) max2ndInd = temp1Ind;
            else max2ndInd = temp2Ind;
            
            if(stones[max1stInd] == stones[max2ndInd]) {
                bool flag1 = false, flag2 = false;
                if(max1stInd == stones.size() - 1) {
                    stones.pop_back();
                    flag1 = true;
                }
                if(max2ndInd == stones.size() - 1) {
                    stones.pop_back();
                    flag2 = true;
                }
                if(!flag1) {
                    swap(stones[max1stInd],stones[stones.size() - 1]);
                    stones.pop_back();
                }
                if(!flag2) {
                    swap(stones[max2ndInd],stones[stones.size() - 1]);
                    stones.pop_back();
                }
            }
            else {
                bool flag1 = false, flag2 = false;
                int t = stones[max1stInd] - stones[max2ndInd];
                if(max2ndInd == stones.size() - 1) {
                    stones.pop_back();
                    flag2 = true;
                }
                if(max1stInd == stones.size() - 1) {
                    stones.pop_back();
                    flag1 = true;
                }
                if(!flag2) {
                    swap(stones[max2ndInd],stones[stones.size() - 1]);
                    stones.pop_back();
                }
                if(!flag1) {
                    swap(stones[max1stInd],stones[stones.size() - 1]);
                    stones.pop_back();
                }
                stones.push_back(t);
            }
        }
        if(stones.size()) return stones[0];
        return 0;
    }
};