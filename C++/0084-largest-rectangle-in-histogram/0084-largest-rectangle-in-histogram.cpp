class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || h[st.top()]>h[i])) {
                int l=h[st.top()];
                st.pop();
                int w=0;
                if(st.empty()) w=i;
                else
                    w=i-st.top()-1;
                ans=max(ans,l*w);
            }
            st.push(i);
        }
        return ans;
    }
};