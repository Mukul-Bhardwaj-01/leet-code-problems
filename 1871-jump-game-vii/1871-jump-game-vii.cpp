class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int l = s.length();

        queue<int> q;
        q.push(0);
        
        int farthest = 1;
        
        while(!q.empty()) {
            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthest);
            int end = min(i + maxJump, l-1);

            for(int k = start; k<=end; ++k) {
                if(s[k] == '0') {
                    if(k == l - 1) return true;
                    q.push(k);
                }
            }
            farthest = end + 1;
        }

        return l == 1;
    }
};