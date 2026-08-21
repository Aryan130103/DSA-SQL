class Solution {
private:
    int f(int i,int j, vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minn=1e9;
        for(int k=i;k<=j;k++){
            int cost=(cuts[j+1]-cuts[i-1])+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            minn=min(minn,cost);
        }
        return dp[i][j]=minn;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        vector<vector<int>>dp(c,vector<int>(c,-1));
        return f(1,c-2,cuts,dp);
    }
};