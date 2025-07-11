class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) available.push(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> count(n, 0);
        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            if (!available.empty()) {
                int room = available.top(); available.pop();
                count[room]++;
                busy.push({end, room});
            } 
            else {
                auto [freeTime, room] = busy.top(); busy.pop();
                count[room]++;
                busy.push({freeTime + (end - start), room});
            }
        }
        int maxCount = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                ans = i;
            }
        }
        return ans;
    }
};