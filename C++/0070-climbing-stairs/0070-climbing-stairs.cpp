class Solution {
public:
    int climbStairs(int n){
        if(n==0 || n==1) return 1;
        int p1=1,p2=1,temp=0;
        for(int i=2;i<=n;i++){
            temp=p1+p2;
            p2=p1;
            p1=temp;
        }
        return p1;
    }
};