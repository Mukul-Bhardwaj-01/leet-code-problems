class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto & p1, const auto & p2) {
            if(p1[0] == p2[0]) return p1[1] > p2[1];
            return p1[0] < p2[0];
        });
        int cnt = 0, i = 1;
        int n = intervals.size();
        int start = intervals[0][0], end = intervals[0][1];
        while(i < n) {
            bool flag = false;
            if(intervals[i][0] < start && intervals[i][1] >= start) {
                start = intervals[i][0];
                flag = true;
            }
            if(intervals[i][1] > end && intervals[i][0] <= end) {
                end = intervals[i][1];
                flag = true;
            }
            if(!flag && intervals[i][0] >= start && intervals[i][1] <= end) {
                cnt++;
            }
            i++;
        }
        return n - cnt;
    }
};
/*
n = 3
    0    1     2
{{1,2},{1,4},{3,4}}         i = 1
start = 1, end = 4*/