class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)   dp[i][0]=i;
        for(int j=1;j<=m;j++)   dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=dp[i][j-1];
                    int del=dp[i-1][j];
                    int replace=dp[i-1][j-1];
                    dp[i][j]=1+min({insert,del,replace});
                }
            }
        }
        return dp[n][m];
    }
};