class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0') return 0;

        int prev1=1,prev2=1;

        for(int i=2;i<=n;i++){
            int onedigit=s[i-1]-'0';
            int twodigit=(s[i-2]-'0')*10+onedigit;

            int curr=0;

            if(onedigit>=1)
                curr+=prev1;
            if(twodigit>=10 && twodigit<=26)
                curr+=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};