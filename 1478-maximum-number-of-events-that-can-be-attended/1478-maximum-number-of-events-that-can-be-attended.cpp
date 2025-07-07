class Solution {
public:
    unordered_map<int, int> parent;
    int find(int d) {
        if (!parent.count(d)) return d;
        return parent[d] = find(parent[d]);
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        for (const auto& e : events) {
            int start = e[0], end = e[1];
            int availableDay = find(start);
            if (availableDay <= end) {
                count++;
                parent[availableDay] = availableDay + 1;
            }
        }
        return count;
    }
};