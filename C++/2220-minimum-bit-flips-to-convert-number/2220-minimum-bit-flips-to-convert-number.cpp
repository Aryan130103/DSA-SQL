class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip=0;
        int num=start^goal;
        while(num){
            num=num&num-1;
            flip++;
        }
        return flip;
    }
};