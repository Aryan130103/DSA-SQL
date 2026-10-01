class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i][0]) || s[i].size()>1 && s[i][0]=='-'){
                st.push(stoi(s[i]));
            }
            else{
                if(s[i][0]=='+'){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(a+b);
                }
                else if(s[i][0]=='-'){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(b-a);
                }
                else if(s[i][0]=='*'){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(a*b);
                }
                else{
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(b/a);
                }
            }
        }
        return st.top();
    }
};