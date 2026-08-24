class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> l(n),r(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty())
                l[i]=0;
            else
                l[i]=st.top()+1;
            
            st.push(i);
        }

        while(!st.empty()) st.pop();

        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();

            if(st.empty()) r[i]=n-1;
            else 
                r[i]=st.top()-1;
            
            st.push(i);
        }

        int maxx=0;
        for(int i=0;i<n;i++){
            maxx=max(maxx,(r[i]-l[i]+1)*heights[i]);
        }
        return maxx;
    }
};