class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        long curr=0,res=0,prev=0;
        char op='+';

        for(int i=0;i<n;i++){
            char ch=s[i];
            
            if(isdigit(ch))
                curr=curr*10+(ch-'0');

            if((!isdigit(ch) && ch!=' ') || i==n-1){
                if(op=='+'){
                    res+=prev;
                    prev=curr;
                }
                else if(op=='-'){
                    res+=prev;
                    prev=-curr;
                }
                else if(op=='*')
                    prev*=curr;
                else if(op=='/')
                    prev/=curr;

                op=ch;
                curr=0;
            }
        }

        return res+prev;
    }
};