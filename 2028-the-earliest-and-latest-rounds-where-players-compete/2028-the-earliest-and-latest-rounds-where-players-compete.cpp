class Solution {
    int n;
    int min_rounds = INT_MAX;
    int max_rounds = INT_MIN;
    void allPossibleMatchups(int mask,int left,int right,int& p1,int& p2,int rounds){
        if(left>=right){
            allPossibleMatchups(mask,0,n-1,p1,p2,rounds+1);
        }else if((mask & (1<<left)) == 0){
            allPossibleMatchups(mask,left+1,right,p1,p2,rounds);
        }else if((mask & (1<<right)) == 0){
            allPossibleMatchups(mask,left,right-1,p1,p2,rounds);
        }else if(left==p1 and right==p2){
            min_rounds = min(min_rounds,rounds);
            max_rounds = max(max_rounds,rounds);
        }else{
            if(left!=p1 and left!=p2)
                allPossibleMatchups(mask^(1<<left),left+1,right-1,p1,p2,rounds);
            
            if(right!=p1 and right!=p2)
                allPossibleMatchups(mask^(1<<right),left+1,right-1,p1,p2,rounds);
        }
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        this->n = n;
        int mask = (1<<n)-1;
        firstPlayer-=1;
        secondPlayer-=1;
        allPossibleMatchups(mask,0,n-1,firstPlayer,secondPlayer,1);
        return {min_rounds,max_rounds};
    }
};
