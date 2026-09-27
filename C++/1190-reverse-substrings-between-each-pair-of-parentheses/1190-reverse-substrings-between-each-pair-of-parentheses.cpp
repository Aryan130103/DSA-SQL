class Solution {
public:
    string reverseParentheses(string s) {
    stack<string> st;
    st.push("");
    for(auto i:s){
        if(i=='(')
            st.push("");
        else if(i==')'){
            string top=st.top();
            st.pop();
            reverse(top.begin(),top.end());
            st.top()+=top;}
        else
            st.top().push_back(i);
    }
    return st.top();
    }
};