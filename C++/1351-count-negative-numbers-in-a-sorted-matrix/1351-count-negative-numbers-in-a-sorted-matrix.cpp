class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int s=0;
        int e=m-1;
        int ans=0;
        while(s<n && e>=0){
            if(grid[s][e]>=0)
                s++;
            else{
                ans+=n-s;
                e--;
            }
        }

        return ans;
    }
};