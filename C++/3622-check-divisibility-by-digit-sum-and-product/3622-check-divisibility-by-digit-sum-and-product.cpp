class Solution {
public:
    bool checkDivisibility(int n) {
        int p=1,s=0,r=0;
        int x=n;
        while(n){
            r=n%10;
            p*=r;
            s+=r;
            n=n/10;
        }
        if(x%(s+p)==0) return true;
        return false;
    }
};