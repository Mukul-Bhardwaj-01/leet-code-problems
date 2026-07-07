class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>> maxHeap(stones.begin(),stones.end());
        while(maxHeap.size() > 1) {
            int t1 = maxHeap.top();
            maxHeap.pop();
            int t2 = maxHeap.top();
            maxHeap.pop();
            if(t1 != t2) {
                maxHeap.push(t1 - t2);
            }
        }
        if(maxHeap.size()) return maxHeap.top();
        return 0;
    }
};