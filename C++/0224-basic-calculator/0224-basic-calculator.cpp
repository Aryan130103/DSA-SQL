class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        long cur=0,res=0,sign=1;
        stack<long> st;

        for(auto& c:s){
            if(isdigit(c))
                cur=cur*10+(c-'0');
            else if(c=='+'){
                res+=cur*sign;
                cur=0;
                sign=1;
            }
            else if(c=='-'){
                res+=cur*sign;
                cur=0;
                sign=-1;
            }
            else if(c=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(c==')'){
                res+=cur*sign;
                res*=st.top();st.pop();
                res+=st.top();st.pop();
                cur=0;
            }
        }
        res+=cur*sign;
        return (int) res;
    }
};