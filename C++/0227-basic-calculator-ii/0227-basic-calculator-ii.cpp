class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int prev=0,curr=0,res=0;
        char og='+';
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isdigit(ch))
                curr=curr*10+(ch-'0');
            if((!isdigit(ch) && ch!=' ') || i==n-1){
                if(og=='+'){
                    res+=prev;
                    prev=curr;
                }   
                else if(og=='-'){
                    res+=prev;
                    prev=-curr;
                }
                else if(og=='*')
                    prev*=curr;
                else if(og=='/')
                    prev/=curr;
                
                og=ch;
                curr=0;
            }
        }
         return res+prev;
    }
};