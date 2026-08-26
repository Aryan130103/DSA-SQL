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
            if(i<n)
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> h(m,0);
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') h[j]++;
                else h[j]=0;
            }   
            maxx=max(maxx,largestRectangleArea(h));
        } 
        return maxx;
    }
};