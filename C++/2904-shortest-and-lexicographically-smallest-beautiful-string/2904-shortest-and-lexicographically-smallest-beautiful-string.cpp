class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int l=0,c=0, minn=1e9;
        string ans="";
        for(int r=0;r<n;r++){
            if(s[r]=='1') 
                c++;
            
            if(c>k){
                if(s[l]=='1') c--;
                l++;
            }

            if(c==k){
                while(s[l]=='0') l++;
                int len=r-l+1;
                if(len<minn){
                    minn=len;
                    ans=s.substr(l,len);
                }
                else if(len==minn){
                    ans=min(ans,s.substr(l,len));
                }
            }
        }
    return ans;
    }
};