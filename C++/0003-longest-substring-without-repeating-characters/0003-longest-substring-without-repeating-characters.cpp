class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,n=s.size(),r=0;
        unordered_map<char,int> m;
        int maxx=0;

        while(r<n){
            if(m.count(s[r]) && m[s[r]]>=l){
                l=m[s[r]]+1;
            }
                        
            m[s[r]]=r;

            maxx=max(maxx,r-l+1);
            r++;
            
        }
        return maxx;
    }
};