class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int len=n+m-dp[n][m];
        string ans="";
        int x=n,y=m;
        while(x>0 && y>0){
            if(s1[x-1]==s2[y-1]){
                ans+=s1[x-1];
                x--;
                y--;
            }
            else if(dp[x-1][y]>dp[x][y-1]) {
                ans+=s1[x-1];
                x--;
            }
            else{ 
                ans+=s2[y-1];
                y--;
            }
        }

        while(x>0){
            ans+=s1[x-1];
            x--;
        }
        while(y>0){
            ans+=s2[y-1];
            y--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};