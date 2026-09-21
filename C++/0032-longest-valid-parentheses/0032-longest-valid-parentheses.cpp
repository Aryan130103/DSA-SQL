class Solution {
public:
    int longestValidParentheses(string s) {
        int len=0;
        int l=0,r=0;
        for(char c:s){
            if(c=='(') l++;
            else r++;

            if(l==r) len=max(len,2*r);
            else if(r>l) l=r=0;
        }
        l=r=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') l++;
            else r++;

            if(l==r) len=max(len,2*l);
            else if(l>r) l=r=0;
        }
        return len;
    }
};