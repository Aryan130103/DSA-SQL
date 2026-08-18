class Solution {
private:
    bool check(string& s,string& t){
        if(s.size()!=t.size()+1) return false;
        int l=0,r=0;
        while(l<s.size() && r<t.size()){
            if(s[l]==t[r]){
                l++;
                r++;
            }
            else l++;
        }
        
        return t.size()==r;
    }
public:
    static bool cond(const string& s1,const string& s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& s) {
        sort(s.begin(),s.end(),cond);
        int n=s.size();
        vector<int> dp(n,1);
        int maxx=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(s[i],s[j]) && dp[i]<1+dp[j])
                    dp[i]=dp[j]+1;
            }
            maxx=max(maxx,dp[i]);
        }
        return maxx;
    }
};