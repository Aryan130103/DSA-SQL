class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0,odd=0;
        int i=0;
        while(n){
            if(i&1){
                if((n&1)==1) odd++;
            }
            else{
                if((n&1)==1) even++;
            }
            i++;
            n=n>>1;
        }
        return {even,odd};
    }
};