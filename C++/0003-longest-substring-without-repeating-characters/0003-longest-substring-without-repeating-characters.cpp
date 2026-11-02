class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,n=s.size(),r=0;
        int freq[128]={0};
        int maxx=0;

        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }

            maxx=max(maxx,r-l+1);
            r++;
            
        }
        return maxx;
    }
};