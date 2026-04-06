class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> st;

        // Store obstacles
        for(auto &obs : obstacles) {
            long long key = (long long)obs[0] * 100000 + obs[1];
            st.insert(key);
        }

        // Directions: N, E, S, W
        vector<pair<int,int>> dirs = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int dir = 0; // start facing North
        int x = 0, y = 0;
        int maxDist = 0;

        for(int cmd : commands) {
            if(cmd == -1) {
                dir = (dir + 1) % 4; // right
            } else if(cmd == -2) {
                dir = (dir + 3) % 4; // left
            } else {
                for(int i = 0; i < cmd; i++) {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;

                    long long key = (long long)nx * 100000 + ny;
                    if(st.count(key)) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};