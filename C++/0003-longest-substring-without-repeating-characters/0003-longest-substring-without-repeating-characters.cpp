class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[128]={};
        int maxx=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            maxx=max(maxx,r-l+1);
        }
        return maxx;
    }
};