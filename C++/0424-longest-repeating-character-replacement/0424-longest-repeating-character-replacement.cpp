class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int freq[26]={};
        int l=0,ans=0,maxx=0;

        for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            maxx=max(maxx,freq[s[r]-'A']);
            while((r-l+1)-maxx>k){
                freq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
        }   
        return ans;
    }
};