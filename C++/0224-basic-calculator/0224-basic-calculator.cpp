class Solution {
public:
    int calculate(string s) {
        stack<long> st;
        long res=0;
        long cur=0;
        int sign=1;

        for(auto& c:s){
            if(isdigit(c)){
                cur=cur*10+(c-'0');
            }
            else if(c=='+'){
                res+=cur*sign;
                sign=1;
                cur=0;
            }
            else if(c=='-'){
                res+=cur*sign;
                sign=-1;
                cur=0;
            }
            else if(c=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(c==')'){
                res+=sign*cur;
                res*=st.top();st.pop();
                res+=st.top();st.pop();
                cur=0;
            }
        }
        res+=sign*cur;
        return (int)res;
    }
};