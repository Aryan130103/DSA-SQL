class Solution {
public:
    bool judgeSquareSum(int c) {
        int b=sqrt(c);
        int i=0;
        while(i<=b){
            long long sum= 1LL*i*i + 1LL*b*b;
            if(sum==c) return true;
            else if(sum<c)
            i++;
            else
            b--;
        }
        return false;
    }
};