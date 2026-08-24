class Solution {
private:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxx=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
               int h=heights[st.top()];
                st.pop();
                int w;
                if(st.empty())w=i;
                else 
                    w=i-st.top()-1;
                maxx=max(maxx,h*w);
            }
            st.push(i);
        }  
        return maxx;
    }
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') h[j]++;
                else h[j]=0;
            }
            int area=maxArea(h);
            ans=max(ans,area);
        }
        return ans;
    }
};