class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int c=0,maxx=0;
        for(auto& i:s){
            if(i=='('){
                st.push(i);
                c++;
                maxx=max(maxx,c);
            }
            else if(i==')'){
                st.pop();
                c--;
            }
        }
        return maxx;
    }
};