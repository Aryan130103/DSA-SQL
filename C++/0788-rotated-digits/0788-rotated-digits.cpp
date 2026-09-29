class Solution {
public:
    int rotatedDigits(int num) {
        int c=0;
        for(int i=1;i<=num;i++){
            int n=i;
            bool changed=false;
            bool valid=true;
            while(n>0){
                int r=n%10;
                if(r==3 || r==4 || r==7) valid=false;
                else if(r==2 || r==5 || r==6 || r==9) changed=true;
                n/=10;
            }
            if(changed && valid) c++; 
        }
        return c;
    }
};