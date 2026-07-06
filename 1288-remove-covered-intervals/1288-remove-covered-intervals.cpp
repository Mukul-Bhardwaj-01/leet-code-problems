class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto & p1, const auto & p2) {
            if(p1[0] == p2[0]) return p1[1] > p2[1];
            return p1[0] < p2[0];
        });
        int cnt = 0, n = intervals.size(), end = intervals[0][1];
        for(int i = 1; i < n; ++i) {
            if(intervals[i][1] <= end) cnt++;
            else end = intervals[i][1];
        }
        return n - cnt;
    }
};
/*
n = 3
    0    1     2
{{1,2},{1,4},{3,4}}         i = 1
start = 1, end = 4*/