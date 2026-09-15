class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int l=0,r=0,n=s.size();
        int ans=0;

        while(r<n){
            if(m[s[r]]==0){
                m[s[r]]++;
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                m[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};