class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0;
        int num=x^y;
        while(num){
            num=num&(num-1);
            c++;
        }
        return c;
    }
};