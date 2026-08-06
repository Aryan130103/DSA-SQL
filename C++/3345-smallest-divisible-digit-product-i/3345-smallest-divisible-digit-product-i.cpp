class Solution {
public:
    int smallestNumber(int n, int t) {
        int x=0;
        if(n==0) return 0;
        while(n<=100){
            int p=1;
            x=n;
            while(x!=0){
            int r=x%10;
            p=p*r;
            x/=10;
            }
            if(p%t==0) return n;
            n++;
        }
        return n;
    }
};