class Solution {
public:
    double myPow(double x, int N) {
        long long n=N;
        bool neg=false;
        if(n<0){
            neg=true;
            n=-n;
        }
        double r=1.0;
        while(n){
            if(n%2){
                r*=x; 
            }
            x=x*x;
            n/=2;
        }
        return neg?1.0/r:r;
    }
};