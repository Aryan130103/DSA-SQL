class Solution {
private:/*
    bool f(int i,int j,string s,string p,vector<vector<int>>& dp){
        if(i==0 && j==0) return true;
        if(i>0 && j==0) return false;
        if(i==0 && j>0){
            for(int x=1;x<j;x++){
                if(p[x-1]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?') 
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[j-1]=='*')
            return dp[i][j]=f(i,j-1,s,p,dp) || f(i-1,j,s,p,dp);

        return dp[i][j]=false;
    }*/
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<bool>prev(m+1,false);
        prev[0]=true;

        for(int j=1;j<=m;j++){
            if(p[j-1]=='*') prev[j]=prev[j-1];
        }    
                

        for(int i=1;i<=n;i++){
            vector<bool>curr(m+1,false);
            for(int j=1;j<=m;j++){

                if(s[i-1]==p[j-1] || p[j-1]=='?') 
                    curr[j]=prev[j-1];
                if(p[j-1]=='*')
                    curr[j]=prev[j] || curr[j-1];
            }
            prev=curr;
        }
    return prev[m];
    }
};