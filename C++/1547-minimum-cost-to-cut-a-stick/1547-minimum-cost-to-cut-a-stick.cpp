class Solution {/*
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
    }*/
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(c+1,0));
        //for(int i=0;i<c-1;i++) dp[i][i+1]=0;
       
        for(int i=c-2;i>=1;i--){
            for(int j=i;j<=c-2;j++){
                 int minn=1e9;
                for(int k=i;k<=j;k++){
                    int cost=(cuts[j+1]-cuts[i-1])+dp[i][k-1]+dp[k+1][j];
                    minn=min(minn,cost);
                }
                dp[i][j]=minn;
            }
        }
        return dp[1][c-2];
    }
};