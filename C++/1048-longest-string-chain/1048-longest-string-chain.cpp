class Solution {
private:
    bool check(string &s,string &t){
        if(s.size()!=t.size()+1) return false;
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else i++;
        }

        return j==t.size();
    }

public:
    static bool comp(const string &s,const string &t){
        return s.size()<t.size();
    }

    int longestStrChain(vector<string>& s) {
        sort(s.begin(),s.end(),comp);
        int n=s.size();
        vector<int> dp(n,1);
        int  maxx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(s[i],s[j]) && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
            maxx=max(maxx,dp[i]);
        }
        return maxx;
    }
};