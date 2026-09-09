class Solution {
public:
    long long countCommas(long long n) {
        /*<1000 0
        >=1000&& <999999 1
        >=1000000 && <999999999 2
        >=1000000000 && <999999999999 3
        >=1000000000000 && <999999999999999 4
        1000000000000000 5*/

        long long ans=0;
        
        if(n>=1e3)
            ans+=min(n,999999LL)-1000+1;
        if(n>=1e6)
            ans+=(min(n,999999999LL)-1e6+1)*2;
        if(n>=1e9)
            ans+=(min(n,999999999999LL)-1e9+1)*3;
        if(n>=1e12)
             ans+=(min(n,999999999999999LL)-1e12+1)*4;
        if(n==1e15)
            ans+=5;

        return ans;
    }
};