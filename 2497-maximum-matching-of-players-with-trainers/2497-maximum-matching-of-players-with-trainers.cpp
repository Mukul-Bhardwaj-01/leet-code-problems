class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0,j=0,match=0;
        while(i<players.size() && j<trainers.size()) {
            if(players[i]<=trainers[j]) {
                i++;
                j++;
                match++;
            }
            else {
                j++;
            }
        }
        return match;
    }
};