class Solution {
public:
    int longestValidParentheses(string s) {
        int len=0,l=0,r=0,n=s.size();

        for(auto ch:s){
            if(ch=='(') l++;
            else r++;

            
            if(l==r) len=max(len,2*r);
            else if(r>l) l=r=0;
        }

        l=r=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') l++;
            else r++;

            if(l==r) len=max(len,2*r);
            else if(l>r) l=r=0;
        }
        return len;
    }
};