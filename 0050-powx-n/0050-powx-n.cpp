class Solution {
public:
    double myPow(double x, long long n) {
        long long p=n;
        if(p<0) p=-p;
        double res=1.0;
        while(p>0) {
            if(p%2!=0) {
                res*=x;
            }
            x*=x;
            p/=2;
        }
        if(n>0) return res;
        return 1/res;
    }
};

/*double res= 1.0;
        if(x==1) return 1;
        long long m=abs(n);
        for(int i=0; i<m; i++) {
            res*=x;
        }
        if(n>0) return res;
        else {
            res=1/res;
            return res;
        }
        return 0;*/